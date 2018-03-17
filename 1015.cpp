#include<iostream>
#include<string>
#include<sstream>
#include<cstdint>
#include<algorithm>

inline int char_to_num(const char &c){
	if(c>='0'&&c<='9'){
		return c - '0';
	}
}

int64_t get_num(const std::string &str,const int &radix){
	int64_t result = 0;
	int64_t base = 1;
	for(auto it=str.rbegin();it!=str.rend();it++){
		result += base*char_to_num(*it);
		base *= radix;
		if(result<0 || base<0){
			return -1;
		}
	}
	return result;
}

int main(){
	int64_t val1;
	int64_t val2;
	int radix;
	std::stringstream ss,ss2;
	while(1){
		std::cin >> val1;
		if(val1 < 0){
			break;
		}
		std::cin >> radix;
		
		if(val1 == 1){
			ss << "No" << std::endl;
			continue;
		}
		
		ss2.str("");
		ss2.clear();
		val2 = val1;
		while(val2>0){
			int t = val2%radix;
			val2 = (val2-t)/radix;
			ss2 << t;
//			std::cout << "val2=" << val2 << " t=" << t << std::endl;
		}
		std::string str = ss2.str();
//		std::cout << "str=" << str << std::endl;
//		std::reverse(str.begin(),str.end());
		val2 = get_num(str,radix);
		
//		std::cout << val1 << ' ' << val2 << std::endl;

		if(val2 == 1){
			ss << "No" << std::endl;
			continue;
		}
		
		if(val1>val2){
			std::swap(val1,val2);
		}
		
		bool ok = true;
		int64_t i=2,j=4;
		while(j<=val2){
			if( (j<=val1&&val1%i==0) || val2%i==0 ){
				ok = false;
				break;
			}
			i++;
			j = i*i;
		}
		if(ok){
			ss << "Yes" << std::endl;
		}else{
			ss << "No" << std::endl;
		}
		
	}
	std::cout << ss.str();
	return 0;
} 

/*
1015. Reversible Primes (20)
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
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (< 105) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:

The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:

For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.

Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
*/
