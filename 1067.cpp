#include<iostream>
#include<iomanip>
#include<map>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<cstdint>
#include<cmath>
#include<deque>
#include<queue>
#include<list>
#include<algorithm>
#include<iterator>
#include<memory>
#include<stack>

typedef std::vector<int>::iterator it_t;

int check(int start,const it_t &begin,const it_t &end){
	for(int i=start; begin+i < end ;i++){
		if(begin[i] != i){
			return i;
		}
	}
	return 0;
}

int main(){
	int n;
	std::cin >> n;
	std::vector<int> vec(n);
	for(int i=0;i<n;i++){
		std::cin >> vec[i];
	}
	int count = 0;
	auto begin = vec.begin();
	auto end = vec.end();
	int pos = check(1,begin,end);
	while(pos){
		if(vec[0] == 0){
//			std::cout << "0swap(" << vec[0] << ',' << vec[pos] << ')' << std::endl;
			std::swap(vec[0],vec[pos]);
			count++;
		}
		while(vec[0] != 0){
//			std::cout << "1swap(" << vec[0] << ',' << vec[vec[0]] << ')' << std::endl;
			std::swap(vec[0],vec[vec[0]]);
			count++;
		}
		pos = check(pos,begin,end);
	}
	std::cout << count << std::endl;
	return 0;
}
/*
1067. Sort with Swap(0,*) (25)
时间限制
150 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Given any permutation of the numbers {0, 1, 2,..., N-1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}

Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

Input Specification:

Each input file contains one test case, which gives a positive N (<=105) followed by a permutation sequence of {0, 1, ..., N-1}. All the numbers in a line are separated by a space.

Output Specification:

For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

Sample Input:
10 3 5 7 2 6 4 9 0 8 1
Sample Output:
9
*/

/*
该题的思路很容易想到，不过若不注重技巧会超时。
若用数组v[]来容纳所有元素，该题目的目的就是通过最少的交换次数（注意只能必须是0与另一个数交换）
来使得对于所有i均有v[i]== i,既然要求得最少交换次数，那就该尽量使每一次交换都能有一个元素被换到正确位置
（且该元素不会再次被交换），下面分两种情况讨论：
1. v[0] != 0:
   说明0不在正确位置上，那要通过变换使得v[0] == 0才行。此时该将0与该处在0所处的位置上的元素进行
交换，例如上面的举例{4, 0, 2, 1, 3}，此时该将0与1（0所处的位置序号为1，即这本该是1所在的位置）交换，
通过类似的多次交换直到v[0] == 0;
2. v[0] == 0:
 此时0已在正确位置上了，但其他元素还没有全处于正确位置。所以必须得有一次废交换了（即交换后没
能使一个元素到达正确位置），怎么交换，肯定不能将0与一个已处在正确位置的元素交换吧（要不还得将这个元素
交换回来），所以肯定是将0与一个处于不正确位置的元素交换。

有个关键的问题是判断排序的结束， 注意到上面需要用到错误位置的元素，因此设计一个函数每次从位置1开始找错误元素，如果找不到返回0，注意不要从0开始找，这样只要找到的位置不是0，则说明还有未完成排序的元素，如果从0开始找，就无法判断是否排序结束了，因为我们用0判断是否找不到，并且我们不必担心第一个错误位置是0的情况，这个属于0在0位置但排序未完成的情况，在下面有处理。

上面说的比较乱，总结如下：

①从位置1开始查找错误位置，找不到返回0，找到返回相应位置。

②如果查找函数返回0，说明排序结束，直接结束，否则进入③。

③如果0已经归位，但是排序没有结束，如果0不动无法继续排序，这时候让0和上面得到的错误位置交换，这个交换属于无用交换，但必须进行。

④在0没有归位的情况下，不断地把0的位置和应该在这个位置的元素交换，直到0归位，这时候再通过①的查找判断是否结束，没有结束则再继续③、④，直到满足找不到错误位置。
*/
