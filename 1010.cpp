#include<iostream>
#include<string>
#include<sstream>
#include<cstdint>
#include<algorithm>

inline int char_to_num(const char &c){
	if(c>='0'&&c<='9'){
		return c - '0';
	}else if(c>='a'&&c<='z'){
		return c - 'a' + 10;
	}
}

int64_t get_num(const std::string &str,const int &radix,const int64_t max=-1){
	int64_t result = 0;
	int64_t base = 1;
	for(auto it=str.rbegin();it!=str.rend();it++){
		result += base*char_to_num(*it);
		base *= radix;
		if(result<0 || base<0){
			return -1;
		}
		if(max!=-1 && result>max){
			return -1;
		}
	}
	return result;
}

int main(){
	std::string str1,str2;
	int tag;
	int radix;
	std::cin >> str1 >> str2 >> tag >> radix;
	uint64_t real_num;
	if(tag == 2){
		std::swap(str1,str2);
	}
	real_num = get_num(str1,radix);
//	std::cout << real_num << std::endl;
	char max = *std::max_element(str2.begin(),str2.end())+1;
	int64_t i=std::max(char_to_num(max),2);
	while(i<127){//小于127时穷举 
		int64_t test_num = get_num(str2,i,real_num);
		if(test_num < 0){
			std::cout << "Impossible" << std::endl;
			return 0;
		}
		else if(test_num == real_num){
			std::cout << i << std::endl;
			return 0;
		}
		i++;
		if(i<0){
			std::cout << "Impossible" << std::endl;
			return 0;
		}
	}
	int64_t low = i;
	int64_t upp = i << 1;
	while(upp>0){//大于127时二分 
		int64_t test_num = get_num(str2,upp,real_num);
		if(test_num < 0){//二分递减 
			i = (low+upp)/2;
			while(low<=upp){
				test_num = get_num(str2,i,real_num);
				if(test_num < 0){
					upp = i - 1;
				}else if(test_num == real_num){
					std::cout << i << std::endl;
					return 0;
				}else{
					low = i + 1;
				}
				i = (low+upp)/2;
			}
			break;
		}else if(test_num == real_num){
			std::cout << i << std::endl;
			return 0;
		}else{//乘2递增 
			low = upp;
			upp = upp << 1;
		}
	}
	std::cout << "Impossible" << std::endl;
	return 0;
}

/*
1010. Radix (25)
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
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.

Input Specification:

Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
N1 N2 tag radix
Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.

Output Specification:

For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.

Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible
*/
