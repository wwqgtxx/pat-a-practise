#include<iostream>
#include<sstream>

int main(){
	std::string str;
	std::cin >> str;
	int sum = 0;
	for(std::string::iterator it=str.begin();it!=str.end();it++){
		sum += (*it)- '0';
	}
//	std::cout << sum << std::endl;
	std::stringstream ss;
	ss << sum;
	str = ss.str();
	for(std::string::iterator it=str.begin();it!=str.end();it++){
		if(it!=str.begin()){
			std::cout << ' ';
		}
		int num = (*it)- '0';
		switch(num){
			case 0:{
				std::cout << "zero";
				break;
			}
			case 1:{
				std::cout << "one";
				break;
			}
			case 2:{
				std::cout << "two";
				break;
			}
			case 3:{
				std::cout << "three";
				break;
			}
			case 4:{
				std::cout << "four";
				break;
			}
			case 5:{
				std::cout << "five";
				break;
			}
			case 6:{
				std::cout << "six";
				break;
			}
			case 7:{
				std::cout << "seven";
				break;
			}
			case 8:{
				std::cout << "eight";
				break;
			}
			case 9:{
				std::cout << "nine";
				break;
			}
		}
	}
	std::cout << std::endl;
	return 0;
}

/*
1005. Spell It Right (20)
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
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five
*/
