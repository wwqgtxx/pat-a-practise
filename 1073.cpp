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
	std::string str;
	std::cin >> str;
	char first = str[0];
	std::string s1;
	auto it=str.begin()+1;
	while(it!=str.end()){
		if(*it == 'E'){
			break;
		}
		if(*it != '.'){
			s1.push_back(*it);
		}
		it++;
	}
	++it;
	char second = (*it++);
	int end = 0;
	while(it!=str.end()){
		end *= 10;
		end += (*it) - '0';
		it++;
	}
	if(second == '-'){
		end *= -1;
	}
	++end;
	if(first == '-'){
		std::cout << '-';
	}
	if(end<=0){//+1.23400E-03
		std::cout << "0.";
		while(end){
			std::cout << '0';
			++end;
		}
		std::cout << s1;
	}else{
		if(end < s1.size()){//+1.23400E+02
			for(int i=0;i<s1.size();i++){
				if(i == end){
					std::cout << '.';
				}
				std::cout << s1[i];
			}
		}else{//-1.2E+10
			end -= s1.size();
			std::cout << s1;
			while(end){
				std::cout << '0';
				--end;
			}
		}
	}
	std::cout << std::endl;
	return 0;
}
/*
1073. Scientific Notation (20)
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
Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.

Now given a real number A in scientific notation, you are supposed to print A in the conventional notation while keeping all the significant figures.

Input Specification:

Each input file contains one test case. For each case, there is one line containing the real number A in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.

Output Specification:

For each test case, print in one line the input number A in the conventional notation, with all the significant figures kept, including trailing zeros,

Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
-12000000000
*/
