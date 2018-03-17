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

std::string get_str(const std::string &a,int n){
	size_t pos = a.find('.');
	if(pos == std::string::npos){
		pos = a.size();
	}
	std::stringstream ss;
	ss << "0.";
	if(a[0] != '0'){
		for(const char &c:a){
			if(c != '.'){
				ss << c;
				--n;
				if(n==0){
					break;
				}
			}
		}
		while(n){
			ss << '0';
			--n;
		}
		ss << "*10^" << pos;
	}else{
		int k=0;
		int i=2;
		for(;i<a.size();i++){
			if(a[i] == '0'){
				k--;
			}else{
				break;
			}
		}
		for(;i<a.size();i++){
			ss << a[i] ;
			--n;
			if(n==0){
				break;
			}
		}
		while(n){
			ss << '0';
			--n;
		}
		if(i == a.size()){
			k = 0;
		}
		ss << "*10^" << k;
	}
	
	return ss.str();
}

void clear(std::string &a){
	for(int i=1;i<a.size();i++){
		if(a[0] == '0' && a[1] != '.'){
			a.erase(a.begin());
			clear(a);
			break;
		}
	}
}

int main(){
	int n;
	std::string a,b;
	std::cin >> n >> a >> b;
	clear(a);
	clear(b);
	a = get_str(a,n);
	b = get_str(b,n);
	if(a==b){
		std::cout << "YES " << a << std::endl;
	}else{
		std::cout << "NO " << a << ' ' << b << std::endl;
	}
	return 0;
} 

/*
1060. Are They Equal (25)
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
If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9 are considered equal since they are both saved as 0.123*105 with simple chopping. Now given the number of significant digits on a machine and two float numbers, you are supposed to tell if they are treated equal in that machine.

Input Specification:

Each input file contains one test case which gives three numbers N, A and B, where N (<100) is the number of significant digits, and A and B are the two float numbers to be compared. Each float number is non-negative, no greater than 10100, and that its total digit number is less than 100.

Output Specification:

For each test case, print in a line "YES" if the two numbers are treated equal, and then the number in the standard form "0.d1...dN*10^k" (d1>0 unless the number is 0); or "NO" if they are not treated equal, and then the two numbers in their standard form. All the terms must be separated by a space, with no extra space at the end of a line.

Note: Simple chopping is assumed without rounding.

Sample Input 1:
3 12300 12358.9
Sample Output 1:
YES 0.123*10^5
Sample Input 2:
3 120 128
Sample Output 2:
NO 0.120*10^3 0.128*10^3
*/

/* 
3 12300 12358.9 
YES 0.123*10^5 
 
1 12300 12358.9 
YES 0.1*10^5 
 
1 1.2300 1.23589 
YES 0.1*10^1 
 
5 1.2300 1.23589 
NO 0.12300*10^1 0.12358*10^1 
 
4 0.01234 0.012345 
YES 0.1234*10^-1 
 
5 0.01234 0.012345 
NO 0.12340*10^-1 0.12345*10^-1 
 
5 0.1234 0.12345 
NO 0.12340*10^0 0.12345*10^0 
 
0 0.11 0 
YES 0.*10^0或者YES 0.0*10^0，都可以AC，测试点应该没有这个例子 
 
1 0.1 0 
NO 0.1*10^0 0.0*10^0 
 
1 0.0 0.1 
NO 0.0*10^0 0.1*10^0 
 
1 0.0 0.000 
YES 0.0*10^0 
 
1 00.0 0.000 
YES 0.0*10^0 
 
4 00.0 0.000 
YES 0.0000*10^0 
 
5 00.0 0.000 
YES 0.00000*10^0 
 
1 05.0 5.000 
YES 0.5*10^1 
 
1 00.01 0.010 
YES 0.1*10^-1 
*/  
