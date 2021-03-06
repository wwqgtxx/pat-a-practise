#include<iostream>
#include<vector>

int main(){
	int num,base;
	std::cin >> num >> base;
	std::vector<int> vec1;
	if(num == 0){
		vec1.emplace_back(0);
	}
	while(num>0){
		vec1.emplace_back(num%base);
		num /= base;
	}
	std::vector<int> vec2(vec1.rbegin(),vec1.rend());
	
	if(vec1 == vec2){
		std::cout << "Yes" << std::endl;
	}else{
		std::cout << "No" << std::endl;
	}
	
	for(auto it=vec2.begin();it!=vec2.end();it++){
		if(it!=vec2.begin()){
			std::cout << ' ';
		}
		std::cout<<*it;
	}
	std::cout << std::endl;
	return 0;
} 

/*
1019. General Palindromic Number (20)
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
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Although palindromic numbers are most often considered in the decimal system, the concept of palindromicity can be applied to the natural numbers in any numeral system. Consider a number N > 0 in base b >= 2, where it is written in standard notation with k+1 digits ai as the sum of (aibi) for i from 0 to k. Here, as usual, 0 <= ai < b for all i and ak is non-zero. Then N is palindromic if and only if ai = ak-i for all i. Zero is written 0 in any base and is also palindromic by definition.

Given any non-negative decimal integer N and a base b, you are supposed to tell if N is a palindromic number in base b.

Input Specification:

Each input file contains one test case. Each case consists of two non-negative numbers N and b, where 0 <= N <= 109 is the decimal number and 2 <= b <= 109 is the base. The numbers are separated by a space.

Output Specification:

For each test case, first print in one line "Yes" if N is a palindromic number in base b, or "No" if not. Then in the next line, print N as the number in base b in the form "ak ak-1 ... a0". Notice that there must be no extra space at the end of output.

Sample Input 1:
27 2
Sample Output 1:
Yes
1 1 0 1 1
Sample Input 2:
121 5
Sample Output 2:
No
4 4 1
*/
