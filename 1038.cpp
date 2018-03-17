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

struct cmp{
	bool operator ()(const std::string &str1,const std::string &str2){
//		return str1+str2 < str2+str1;
//		std::cout << "test:" << str1 << ' ' << str2 << ' ';
		auto it1 = str1.begin();
		auto it2 = str2.begin();
		while(1){
			while(it1 != str1.end() && it2 != str2.end()){
				auto &c1 = *it1;
				auto &c2 = *it2;
				if( c1 < c2 ){
//					std::cout << "True" << std::endl;
					return true;
				}else if( c1 > c2){
//					std::cout << "False" << std::endl;
					return false;
				}
				it1++;
				it2++;
			}
			if(it1 == str1.end() && it2 == str2.end()){
//				std::cout << "False(==)" << std::endl;
				return false;
			}
			else if(it1 == str1.end()){
//				std::cout << "|move it1 to begin|";
				it1 = str1.begin();
			}
			else if(it2 == str2.end()){
//				std::cout << "|move it2 to begin|";
				it2 = str2.begin();
			}
		}
//		std::cout << "False(unknow)" << std::endl;
		return false;
	}	
};


int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<std::string> vec(n);
	for(int i=0;i<n;i++){
		std::cin >> vec[i];
	}
	std::sort(vec.begin(),vec.end(),cmp());
	std::string str;
	for(auto &item:vec){
		str += item;
	}
	while(!str.empty() && str[0]=='0'){
		str.erase(str.begin());
	}
	if(str.empty()){
		std::cout << 0 << std::endl;
	}else{
		std::cout << str << std::endl;
	}
	return 0;
}
/*
1038. Recover the Smallest Number (30)
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
Given a collection of number segments, you are supposed to recover the smallest number from them. For example, given {32, 321, 3214, 0229, 87}, we can recover many numbers such like 32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to different orders of combinations of these segments, and the smallest number is 0229-321-3214-32-87.

Input Specification:

Each input file contains one test case. Each case gives a positive integer N (<=10000) followed by N number segments. Each segment contains a non-negative integer of no more than 8 digits. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the smallest number in one line. Do not output leading zeros.

Sample Input:
5 32 321 3214 0229 87
Sample Output:
22932132143287

*/
