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

int main(){
	std::ios::sync_with_stdio(false);
	std::vector<int64_t> vec;
	int n;
	std::cin >> n;
	vec.resize(n);
	for(int i=0;i<n;i++){
		std::cin >> vec[i];
	}
	int n2;
	std::cin >> n2;
	int n3 = n+n2;
	vec.resize(n+n2);
	for(int i=n;i<n3;i++){
		std::cin >> vec[i];
	}
//	std::sort(vec.begin(),vec.end());
	int n4 = n3/2;
	if(n3%2 == 0){
		n4--;
	}
	std::nth_element(vec.begin(),vec.begin()+n4,vec.end()); 
	std::cout << vec[n4] << std::endl;
} 

/*
1029. Median (25)
时间限制
1000 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.

Given two increasing sequences of integers, you are asked to find their median.

Input

Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (<=1000000) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.

Output

For each test case you should output the median of the two given sequences in a line.

Sample Input
4 11 12 13 14
5 9 10 15 16 17
Sample Output
13
*/
