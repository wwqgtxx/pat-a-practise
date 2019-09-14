#include <algorithm>
#include <cstddef>
#include <functional>
#include <utility>
#include <iterator>
#if __cplusplus >= 201103L
	#include <cstdint>
	#include <type_traits>
	#define PDQSORT_MOVE(x) std::move(x)
#else
	#define PDQSORT_MOVE(x) (x)
#endif
#define PDQSORT_REP_8(x) {x;x;x;x;x;x;x;x;}
#define PDQSORT_TYPE_DEF typedef typename std::iterator_traits<Iter>::value_type T;
namespace pdqsort_detail {
	enum {insertion_sort_threshold = 24,ninther_threshold = 128,partial_insertion_sort_limit = 8,block_size = 64,cacheline_size = 64};
#if __cplusplus >= 201103L
	template<class T> struct is_default_compare : std::false_type { };
	template<class T> struct is_default_compare<std::less<T>> : std::true_type { };
	template<class T> struct is_default_compare<std::greater<T>> : std::true_type { };
#endif
	template<class T> inline int log2(T n) {int log = 0;while (n >>= 1) ++log;return log;}
	template<class Iter, class Compare> inline void insertion_sort(Iter begin, Iter end, Compare comp) {
		PDQSORT_TYPE_DEF;
		if (begin == end) return;
		for (Iter cur = begin + 1; cur != end; ++cur) {
			Iter sift = cur, sift_1 = cur - 1;
			if (comp(*sift, *sift_1)) {
				T tmp = PDQSORT_MOVE(*sift);
				do { *sift-- = PDQSORT_MOVE(*sift_1); }
				while (sift != begin && comp(tmp, *--sift_1));
				*sift = PDQSORT_MOVE(tmp);
			}
		}
	}
	template<class Iter, class Compare> inline void unguarded_insertion_sort(Iter begin, Iter end, Compare comp) {
		PDQSORT_TYPE_DEF;
		if (begin == end) return;
		for (Iter cur = begin + 1; cur != end; ++cur) {
			Iter sift = cur, sift_1 = cur - 1;
			if (comp(*sift, *sift_1)) {
				T tmp = PDQSORT_MOVE(*sift);
				do { *sift-- = PDQSORT_MOVE(*sift_1); }
				while (comp(tmp, *--sift_1));
				*sift = PDQSORT_MOVE(tmp);
			}
		}
	}
	template<class Iter, class Compare> inline bool partial_insertion_sort(Iter begin, Iter end, Compare comp) {
		PDQSORT_TYPE_DEF;
		if (begin == end) return true;
		int limit = 0;
		for (Iter cur = begin + 1; cur != end; ++cur) {
			if (limit > partial_insertion_sort_limit) return false;
			Iter sift = cur, sift_1 = cur - 1;
			if (comp(*sift, *sift_1)) {
				T tmp = PDQSORT_MOVE(*sift);
				do {*sift-- = PDQSORT_MOVE(*sift_1);}while (sift != begin && comp(tmp, *--sift_1));
				*sift = PDQSORT_MOVE(tmp);
				limit += cur - sift;
			}
		}
		return true;
	}
	template<class Iter, class Compare> inline void sort2(Iter a, Iter b, Compare comp) {if (comp(*b, *a)) std::iter_swap(a, b);}
	template<class Iter, class Compare> inline void sort3(Iter a, Iter b, Iter c, Compare comp) {sort2(a, b, comp);sort2(b, c, comp);sort2(a, b, comp);}
	template<class T> inline T* align_cacheline(T* p) {
#if defined(UINTPTR_MAX) && __cplusplus >= 201103L
		std::uintptr_t ip = reinterpret_cast<std::uintptr_t>(p);
#else
		std::size_t ip = reinterpret_cast<std::size_t>(p);
#endif
		ip = (ip + cacheline_size - 1) & -cacheline_size;
		return reinterpret_cast<T*>(ip);
	}
	template<class Iter> inline void swap_offsets(Iter first, Iter last,
							 unsigned char* offsets_l, unsigned char* offsets_r,
							 int num, bool use_swaps) {
		PDQSORT_TYPE_DEF;
		if (use_swaps) {
			for (int i = 0; i < num; ++i) {std::iter_swap(first + offsets_l[i], last - offsets_r[i]);}
		} else if (num > 0) {
			Iter l = first + offsets_l[0], r = last - offsets_r[0];
			T tmp(PDQSORT_MOVE(*l)); *l = PDQSORT_MOVE(*r);
			for (int i = 1; i < num; ++i) {l = first + offsets_l[i]; *r = PDQSORT_MOVE(*l);r = last - offsets_r[i]; *l = PDQSORT_MOVE(*r);}
			*r = PDQSORT_MOVE(tmp);
		}
	}
	template<class Iter, class Compare> inline std::pair<Iter, bool> partition_right_branchless(Iter begin, Iter end, Compare comp) {
		PDQSORT_TYPE_DEF;
		T pivot(PDQSORT_MOVE(*begin));
		Iter first = begin, last = end;
		while (comp(*++first, pivot));
		if (first - 1 == begin) while (first < last && !comp(*--last, pivot));else while (!comp(*--last, pivot));
		bool already_partitioned = first >= last;
		if (!already_partitioned) {std::iter_swap(first, last);++first;}
		unsigned char offsets_l_storage[block_size + cacheline_size], offsets_r_storage[block_size + cacheline_size];
		unsigned char* offsets_l = align_cacheline(offsets_l_storage), *offsets_r = align_cacheline(offsets_r_storage);
		int num_l, num_r, start_l, start_r;
		num_l = num_r = start_l = start_r = 0;
		while (last - first > 2 * block_size) {
			if (num_l == 0) {start_l = 0;Iter it = first;for (unsigned char i = 0; i < block_size;) {PDQSORT_REP_8({offsets_l[num_l] = i++; num_l += !comp(*it, pivot); ++it;})}}
			if (num_r == 0) {start_r = 0;Iter it = last; for (unsigned char i = 0; i < block_size;) {PDQSORT_REP_8({offsets_r[num_r] = ++i; num_r += comp(*--it, pivot);})}}
			int num = std::min(num_l, num_r);
			swap_offsets(first, last, offsets_l + start_l, offsets_r + start_r, num, num_l == num_r);
			num_l -= num; num_r -= num;
			start_l += num; start_r += num;
			if (num_l == 0) first += block_size;
			if (num_r == 0) last -= block_size;
		}
		int l_size = 0, r_size = 0;
		int unknown_left = (last - first) - ((num_r || num_l) ? block_size : 0);
		if (num_r) {l_size = unknown_left;r_size = block_size;} else if (num_l) {l_size = block_size;r_size = unknown_left;} else {l_size = unknown_left/2;r_size = unknown_left - l_size;}
		if (unknown_left && !num_l) {start_l = 0;Iter it = first;for (unsigned char i = 0; i < l_size;) {offsets_l[num_l] = i++; num_l += !comp(*it, pivot); ++it;}}
		if (unknown_left && !num_r) {start_r = 0;Iter it = last;for (unsigned char i = 0; i < r_size;) {offsets_r[num_r] = ++i; num_r += comp(*--it, pivot);}}
		int num = std::min(num_l, num_r);
		swap_offsets(first, last, offsets_l + start_l, offsets_r + start_r, num, num_l == num_r);
		num_l -= num; num_r -= num;
		start_l += num; start_r += num;
		if (num_l == 0) first += l_size;
		if (num_r == 0) last -= r_size;
		if (num_l) {offsets_l += start_l;while (num_l--) std::iter_swap(first + offsets_l[num_l], --last);first = last;}
		if (num_r) {offsets_r += start_r;while (num_r--) std::iter_swap(last - offsets_r[num_r], first), ++first;last = first;}
		Iter pivot_pos = first - 1;
		*begin = PDQSORT_MOVE(*pivot_pos);
		*pivot_pos = PDQSORT_MOVE(pivot);
		return std::make_pair(pivot_pos, already_partitioned);
	}
	template<class Iter, class Compare> inline std::pair<Iter, bool> partition_right(Iter begin, Iter end, Compare comp) {
		PDQSORT_TYPE_DEF;
		T pivot(PDQSORT_MOVE(*begin));
		Iter first = begin,last = end;
		while (comp(*++first, pivot));
		if (first - 1 == begin) while (first < last && !comp(*--last, pivot));else while (!comp(*--last, pivot));
		bool already_partitioned = first >= last;
		while (first < last) {std::iter_swap(first, last);while (comp(*++first, pivot));while (!comp(*--last, pivot));}
		Iter pivot_pos = first - 1;
		*begin = PDQSORT_MOVE(*pivot_pos);
		*pivot_pos = PDQSORT_MOVE(pivot);
		return std::make_pair(pivot_pos, already_partitioned);
	}
	template<class Iter, class Compare> inline Iter partition_left(Iter begin, Iter end, Compare comp) {
		PDQSORT_TYPE_DEF;
		T pivot(PDQSORT_MOVE(*begin));
		Iter first = begin,last = end;
		while (comp(pivot, *--last));
		if (last + 1 == end) while (first < last && !comp(pivot, *++first));else while (!comp(pivot, *++first));
		while (first < last) {std::iter_swap(first, last);while (comp(pivot, *--last));while (!comp(pivot, *++first));}
		Iter pivot_pos = last;
		*begin = PDQSORT_MOVE(*pivot_pos);
		*pivot_pos = PDQSORT_MOVE(pivot);
		return pivot_pos;
	}
	template<class Iter, class Compare, bool Branchless> inline void pdqsort_loop(Iter begin, Iter end, Compare comp, int bad_allowed, bool leftmost = true) {
		typedef typename std::iterator_traits<Iter>::difference_type diff_t;
		while (true) {
			diff_t size = end - begin;
			if (size < insertion_sort_threshold) {if (leftmost) insertion_sort(begin, end, comp); else unguarded_insertion_sort(begin, end, comp);return;}
			diff_t s2 = size / 2;
			if (size > ninther_threshold) {sort3(begin, begin + s2, end - 1, comp);sort3(begin + 1, begin + (s2 - 1), end - 2, comp);sort3(begin + 2, begin + (s2 + 1), end - 3, comp);sort3(begin + (s2 - 1), begin + s2, begin + (s2 + 1), comp);std::iter_swap(begin, begin + s2);} else sort3(begin + s2, begin, end - 1, comp);
			if (!leftmost && !comp(*(begin - 1), *begin)) {begin = partition_left(begin, end, comp) + 1;continue;}
			std::pair<Iter, bool> part_result = Branchless ? partition_right_branchless(begin, end, comp): partition_right(begin, end, comp);
			Iter pivot_pos = part_result.first;
			bool already_partitioned = part_result.second;
			diff_t l_size = pivot_pos - begin, r_size = end - (pivot_pos + 1);
			bool highly_unbalanced = l_size < size / 8 || r_size < size / 8;
			if (highly_unbalanced) {
				if (--bad_allowed == 0) {std::make_heap(begin, end, comp);std::sort_heap(begin, end, comp);return;}
				if (l_size >= insertion_sort_threshold) {std::iter_swap(begin,begin + l_size / 4);std::iter_swap(pivot_pos - 1, pivot_pos - l_size / 4);if (l_size > ninther_threshold) {std::iter_swap(begin + 1,begin + (l_size / 4 + 1));std::iter_swap(begin + 2,begin + (l_size / 4 + 2));std::iter_swap(pivot_pos - 2, pivot_pos - (l_size / 4 + 1));std::iter_swap(pivot_pos - 3, pivot_pos - (l_size / 4 + 2));}}
				if (r_size >= insertion_sort_threshold) {std::iter_swap(pivot_pos + 1, pivot_pos + (1 + r_size / 4));std::iter_swap(end - 1,end - r_size / 4);if (r_size > ninther_threshold) {std::iter_swap(pivot_pos + 2, pivot_pos + (2 + r_size / 4));std::iter_swap(pivot_pos + 3, pivot_pos + (3 + r_size / 4));std::iter_swap(end - 2,end - (1 + r_size / 4));std::iter_swap(end - 3,end - (2 + r_size / 4));}}
			} else {
				if (already_partitioned && partial_insertion_sort(begin, pivot_pos, comp)&& partial_insertion_sort(pivot_pos + 1, end, comp)) return;
			}
			pdqsort_loop<Iter, Compare, Branchless>(begin, pivot_pos, comp, bad_allowed, leftmost);
			begin = pivot_pos + 1;
			leftmost = false;
		}
	}
}
template<class Iter, class Compare> inline void pdqsort(Iter begin, Iter end, Compare comp) {
	if (begin == end) return;
#if __cplusplus >= 201103L
	pdqsort_detail::pdqsort_loop<Iter, Compare, pdqsort_detail::is_default_compare<typename std::decay<Compare>::type>::value && std::is_arithmetic<typename std::iterator_traits<Iter>::value_type>::value>(begin, end, comp, pdqsort_detail::log2(end - begin));
#else
	pdqsort_detail::pdqsort_loop<Iter, Compare, false>(begin, end, comp, pdqsort_detail::log2(end - begin));
#endif
}
template<class Iter> inline void pdqsort(Iter begin, Iter end) {
	PDQSORT_TYPE_DEF;
	pdqsort(begin, end, std::less<T>());
}
template<class Iter, class Compare> inline void pdqsort_branchless(Iter begin, Iter end, Compare comp) {
	if (begin == end) return;
	pdqsort_detail::pdqsort_loop<Iter, Compare, true>(begin, end, comp, pdqsort_detail::log2(end - begin));
}
template<class Iter> inline void pdqsort_branchless(Iter begin, Iter end) {
	PDQSORT_TYPE_DEF;
	pdqsort_branchless(begin, end, std::less<T>());
}
#undef PDQSORT_MOVE
#undef PDQSORT_REP_8
#undef PDQSORT_TYPE_DEF

#include<cstdio>
#include<cstring>
#include<stdint.h>
#include<algorithm>
#include<set>
#include<iostream> 
#include<vector>
#include<map>

int main(){
	int64_t n,p;
	scanf("%d%d",&n,&p);
	std::vector<int64_t> vec(n);
	for(int i=0;i<n;i++){
		scanf("%d",&vec[i]);
	}
	pdqsort(vec.begin(),vec.end());
	int j=0;
	int max=0;
	for(int i=0;i<n;i++){
		const int64_t &m = vec[i];
		while(j<n){
			const int64_t &M = vec[j];
			if(M<=m*p){
				j++;
			}else{
				break;
			}
		}
		max = std::max(j-i,max);
	}
	printf("%d",max);
} 

/*
1085 Perfect Sequence （25 分）
Given a sequence of positive integers and another positive integer p. The sequence is said to be a perfect sequence if M≤m×p where M and m are the maximum and minimum numbers in the sequence, respectively.

Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.

Input Specification:
Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N (≤10
?5
?? ) is the number of integers in the sequence, and p (≤10
?9
?? ) is the parameter. In the second line there are N positive integers, each is no greater than 10
?9
?? .

Output Specification:
For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.

Sample Input:
10 8
2 3 20 4 5 1 6 7 8 9
Sample Output:
8
作者: CAO, Peng
单位: 浙江大学
时间限制: 200 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
