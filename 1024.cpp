#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstdint>

int main(){
	std::string str;
	std::cin >> str;
	int k;
	std::cin >> k;
	int i;
	std::string str2,str3;
	uint64_t num1,num2;
	str2.assign(str.rbegin(),str.rend());
	for(i=0;i<k;i++){
		if(str == str2){
			break;
		}
		str3.clear();
		int over = 0;
		for(auto it1=str.begin(),it2=str2.begin();it1!=str.end()&&it2!=str2.end();it1++,it2++){
			int n = *it1 - '0';
			n += *it2 - '0';
			n += over;
			over = n/10;
			n -= over*10;
			str3.push_back(n + '0');
		}
		if(over>0){
			str3.push_back(over + '0');
		}
		str.assign(str3.rbegin(),str3.rend());
		str2.swap(str3);
	}
	std::cout << str << std::endl;
	std::cout << i << std::endl;
}

/*
1024. Palindromic Number (25)
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

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.

Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.

Input Specification:

Each input file contains one test case. Each case consists of two positive numbers N and K, where N (<= 1010) is the initial numer and K (<= 100) is the maximum number of steps. The numbers are separated by a space.

Output Specification:

For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.

Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3

*/
