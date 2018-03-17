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

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::string str;
	std::getline(std::cin,str);
	int max = 1;
	for(auto it1 = str.begin();it1 != str.end();++it1){
		for(auto it2 = --str.end();it2 != it1;--it2){
			int value = it2 - it1 + 1;
			if(value < max){
				break;
			}
//			std::cout << "Test : " << std::string(it1,it2+1) << std::endl;
			auto iit1 = it1;
			auto iit2 = it2;
			bool equals = true;
			while(iit1 < iit2){
				if( (*iit1) != (*iit2) ){
					equals = false;
					break;
				}
				++iit1;
				--iit2;
			}
			if(equals){
//				std::cout << value << std::endl;
				max = std::max(value,max);
				break;
			}
		}
	}
	std::cout << max << std::endl;
	return 0;
	
} 
/*
1040. Longest Symmetric String (25)
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
Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given "Is PAT&TAP symmetric?", the longest symmetric sub-string is "s PAT&TAP s", hence you must output 11.

Input Specification:

Each input file contains one test case which gives a non-empty string of length no more than 1000.

Output Specification:

For each test case, simply print the maximum length in a line.

Sample Input:
Is PAT&TAP symmetric?
Sample Output:
11

*/
