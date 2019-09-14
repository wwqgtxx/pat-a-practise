#include<cstdio>
#include<stdint.h>
#include<algorithm>
#include<set>
#include<iostream> 
int64_t gcd(int64_t a,int64_t b){
    if (b == 0){
        return a;
    }     
    return gcd(b,a%b);
}

int64_t lcm(int64_t a,int64_t b){
    return a/gcd(a,b)*b;
}

struct number_t{
	int64_t integer;
	int64_t numerator;
	int64_t denominator;
	bool negative;
	
	number_t():integer(0), numerator(0),denominator(0),negative(false){
	}
	
	void to_simple(){
		if(numerator==0 || denominator==0){
			numerator = 0;
			numerator = 0;
		}else{
			if(negative){
				negative=false;
				numerator = -numerator;
			}
			int64_t t = gcd(numerator,denominator);
			numerator /= t;
			denominator /= t;
		}
	}
	
	void parse_integer(){
		integer += numerator/denominator;
		numerator = numerator%denominator;
	}
	
	number_t& operator+=(const number_t &other){
		if(denominator==0){
			*this = other;
		}else if(other.denominator != 0){
			int64_t t = gcd(denominator,other.denominator);
			int64_t t1 = denominator/t;
			int64_t t2 = other.denominator/t;
			denominator *= t2;
			numerator = numerator*t2 + other.numerator*t1;
		}
		to_simple();
		return *this;
	}
};

int main(){
	std::ios::sync_with_stdio(false);
	number_t number,number1;
	int n;
	std::cin >> n;
	std::string str;
	std::getline(std::cin,str);
	std::getline(std::cin,str);
	str.push_back(' ');
	bool flag = true;
	for(std::string::iterator it = str.begin();it!=str.end();it++){
		char &c = *it;
		switch(c){
			case ' ':{
				number1.to_simple();
				number += number1;
				number1.denominator = 0;
				number1.integer = 0;
				number1.numerator = 0;
				number1.negative = false;
				flag = true;
				break;
			}
			case '/':{
				flag = false;
				break;
			}
			case '-':{
				number1.negative = true;
				break;
			}
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':{
				if(flag){
					number1.numerator *= 10;
					number1.numerator += c-'0';
				}else{
					number1.denominator *= 10;
					number1.denominator += c-'0';
				}
				break;
			}
		}
	}
	number.parse_integer();
	if(number.integer!=0){
		if(number.numerator!=0 && number.denominator!=0){
			std::cout << number.integer << ' '  
			<< number.numerator << '/' 
			<< number.denominator;
		}else{
			std::cout << number.integer;
		}
	}else{
		if(number.numerator!=0 && number.denominator!=0){
			std::cout << number.numerator << '/' << number.denominator;
		}else{
			std::cout << '0';
		}
	}
	std::cout.flush();
	return 0;
} 

/*
1081 Rational Sum （20 分）
Given N rational numbers in the form numerator/denominator, you are supposed to calculate their sum.

Input Specification:
Each input file contains one test case. Each case starts with a positive integer N (≤100), followed in the next line N rational numbers a1/b1 a2/b2 ... where all the numerators and denominators are in the range of long int. If there is a negative number, then the sign must appear in front of the numerator.

Output Specification:
For each test case, output the sum in the simplest form integer numerator/denominator where integer is the integer part of the sum, numerator < denominator, and the numerator and the denominator have no common factor. You must output only the fractional part if the integer part is 0.

Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:
3 1/3
Sample Input 2:
2
4/3 2/3
Sample Output 2:
2
Sample Input 3:
3
1/3 -1/6 1/8
Sample Output 3:
7/24
作者: CHEN, Yue
单位: 浙江大学
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
