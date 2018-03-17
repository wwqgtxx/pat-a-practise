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

int main(){
	int n;
	std::cin >> n;
	int count = 0;
	int x = 1;
	while(n/x>0){
		int right = n%x;
		int nx = n/x;
		int left = nx/10;
		int current = nx%10;
		if(current == 0){
			count += left * x;
		}else if(current == 1){
			count += left * x + right + 1;
		}else{
			count += (left+1) * x ;
		}
		x *= 10; 
	}
	std::cout << count << std::endl;
}

/*
分别考虑每一位出现1的情况，将其相加

循环考虑当前位，高位，低位

如果当前位==0，则该为出现1 的情况由更高位决定，= 更高为数字*当前位数

如果当前位==1，则该为出现1 的情况受更高位以及低位影响，= （更高为数字*当前位数）+（低位数字+1）

如果当前位>1，则该为出现1 的情况由更高位决定，= (更高为数字+1)*当前位数
*/

/*
1049. Counting Ones (30)
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
The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

Input Specification:

Each input file contains one test case which gives the positive N (<=230).

Output Specification:

For each test case, print the number of 1's in one line.

Sample Input:
12
Sample Output:
5
*/
