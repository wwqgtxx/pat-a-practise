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

bool isPrime(int c){
	if(c == 1){
		return false;
	}
	if(c == 2){
		return true;
	}
	int t = sqrt(c);
	for(int i=2;i<=t;i++){
		if(c%i == 0){
			return false;
		}
	}
	return true;
} 

int main(){
	int m,n;
	std::cin >> m >> n;
	while(!isPrime(m)){
		++m;
	}
//	std::cout << m << std::endl;
	std::vector<char> vec(m,0);
	int t;
	std::stringstream ss;
	for(int i=0;i<n;i++){
		std::cin >> t;
		
		int hash = t % m;
		int j = 0;
		while(j<m){
			if(vec[hash]==0){
				vec[hash] = 1;
				break;
			}
			++j;
			hash = (t+j*j) % m;
		}
		if(j == m){
			ss << '-' << ' '; 
		}else{
			ss << hash << ' ';
		}
		
	}
	std::string str = ss.str();
	str.pop_back();
	std::cout << str << std::endl;
}

/*
1078. Hashing (25)
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
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. The hash function is defined to be "H(key) = key % TSize" where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.

Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers: MSize (<=104) and N (<=MSize) which are the user-defined table size and the number of input numbers, respectively. Then N distinct positive integers are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead.

Sample Input:
4 4
10 6 4 15
Sample Output:
0 1 4 -

*/
