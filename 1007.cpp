#include<iostream>
#include<vector>

int main(){
	std::vector<int> vec;
	int k;
	std::cin >> k;
	vec.resize(k);
	bool all_negative = true;
	for(int i=0;i<k;i++){
		std::cin >> vec[i];
		if(vec[i]>=0){
			all_negative = false;
		}
	}
	if(all_negative){
		std::cout << "0 " << vec[0] << ' ' << vec[k-1] << std::endl;
		return 0;
	}
	bool is_first = true;
	int sum = 0,begin = 0,end = k-1;
	int tmp_sum = 0,tmp_begin = 0,tmp_end = 0;
	for(int i=0;i<k;i++){
		if(tmp_sum >= 0){
			tmp_sum += vec[i];
			tmp_end = i;
		}else{
			tmp_sum = vec[i];
			tmp_begin = i;
			tmp_end = i;
		}
		if(tmp_sum > sum || (is_first && tmp_sum == 0)){
			is_first = false;
			sum = tmp_sum;
			begin = tmp_begin;
			end = tmp_end;
		}
	}
	std::cout << sum << ' ' << vec[begin] << ' ' << vec[end] << std::endl;
	return 0;
}

/*
1007. Maximum Subsequence Sum (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/
