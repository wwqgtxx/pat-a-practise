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

void int2arr(int n,std::vector<int> &vec){
	vec.clear();
	vec.resize(4);
	for(int i=0;i<4;i++){
		vec[i] = n % 10;
		n /= 10;
	}
}

int arr2int(const std::vector<int> &vec){
	return vec[0] + vec[1]*10 + vec[2]*100 + vec[3]*1000;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::vector<int> vec(4);
	std::stringstream ss;
	int a,b,c;
	
	std::cin >> a;
	int2arr(a,vec);
	
	if((vec[0] == vec[1]) && (vec[1] == vec[2]) && (vec[2] == vec[3])){
		ss << std::setfill('0') << std::setw(4) << a 
			<< " - " 
			<< std::setfill('0') << std::setw(4) << a 
			<< " = " 
			<< std::setfill('0') << std::setw(4) << 0 
			<< std::endl; 
	}else{
		while(1){
			std::sort(vec.begin(),vec.end());
			a = arr2int(vec);
			std::reverse(vec.begin(),vec.end());
			b = arr2int(vec);
			c = a-b;
			ss << std::setfill('0') << std::setw(4) << a 
			    << " - " 
				<< std::setfill('0') << std::setw(4) << b 
				<< " = " 
				<< std::setfill('0') << std::setw(4) << c 
				<< std::endl;
			if(c == 6174){
				break;
			}
			int2arr(c,vec);
		}
	}
	
	std::cout << ss.str();
	return 0;
}

/*
1069. The Black Hole of Numbers (20)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
For any 4-digit integer except the ones with all the digits being the same, if we sort the digits in non-increasing order first, and then in non-decreasing order, a new number can be obtained by taking the second number from the first one. Repeat in this manner we will soon end up at the number 6174 -- the "black hole" of 4-digit numbers. This number is named Kaprekar Constant.

For example, start from 6767, we'll get:

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

Given any 4-digit number, you are supposed to illustrate the way it gets into the black hole.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range (0, 10000).

Output Specification:

If all the 4 digits of N are the same, print in one line the equation "N - N = 0000". Else print each step of calculation in a line until 6174 comes out as the difference. All the numbers must be printed as 4-digit numbers.

Sample Input 1:
6767
Sample Output 1:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
Sample Input 2:
2222
Sample Output 2:
2222 - 2222 = 0000
*/ 
