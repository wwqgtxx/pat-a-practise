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

inline bool isPrime(const int &n){
	int tmp = std::sqrt(n);
	for(int i=2;i<=tmp;i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	long long int n;
	std::cin >> n;
	std::cout << n << '=';
	if(n == 1){
		std::cout << 1;
	}else{
		for(int i=2;i<=n;i++){
			if(isPrime(i)){
				int k=0;
				while(n%i == 0){
					n /= i;
					k++; 
				}
				if(k>0){
					std::cout << i;
					if(k>1){
						std::cout << '^' << k;
					}
					if(n>1){
						std::cout << '*';
					}	
				}
			}	
		}
	}
	
	std::cout << std::endl;
}

/*
1059. Prime Factors (25)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
HE, Qinming
Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p1^k1 * p2^k2 *…*pm^km.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:

Factor N in the format N = p1^k1 * p2^k2 *…*pm^km, where pi's are prime factors of N in increasing order, and the exponent ki is the number of pi -- hence when there is only one pi, ki is 1 and must NOT be printed out.

Sample Input:
97532468
Sample Output:
97532468=2^2*11*17*101*1291

*/
