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

int main(){
	int t; 
	std::cin >> t;
	std::stringstream ss;
	int64_t a,b,c;
	__int128_t a1,b1,c1;
	for(int i=0;i<t;i++){
		std::cin >> a >> b >> c;
		a1 = a;
		b1 = b;
		c1 = c;
		ss << "Case #" << i+1 << ": ";
		if(a1+b1 > c1){
			ss << "true";
		}else{
			ss << "false";
		}
		ss << std::endl;
	}
	std::cout << ss.str();
	return 0;
} 

/*
1065. A+B and C (64bit) (20)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
HOU, Qiming
Given three integers A, B and C in [-263, 263], you are supposed to tell whether A+B > C.

Input Specification:

The first line of the input gives the positive number of test cases, T (<=10). Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.

Output Specification:

For each test case, output in one line "Case #X: true" if A+B>C, or "Case #X: false" otherwise, where X is the case number (starting from 1).

Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
Sample Output:
Case #1: false
Case #2: true
Case #3: false
*/
