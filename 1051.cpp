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
	int m,n,k;
	std::deque<int> stack;
	std::cin >> m >> n >> k;
	std::vector<std::deque<int>> vec(k,std::deque<int>(n));
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			std::cin >> vec[i][j];
		}
	}
	for(int i=0;i<k;i++){
		auto &data = vec[i];
		stack.clear();
		bool can = true;
		int now = 0;
		while(!data.empty()){
			if(stack.empty()){
				stack.emplace_back(++now);
			}
			int d = data.front();
			int back = stack.back();
			if(d > back){
				if(stack.size() < m){
					stack.emplace_back(++now);
				}else{
					can = false;
					break;
				}
			}else if(d == back){
				stack.pop_back();
				data.pop_front();
			}else{
				can = false;
				break;
			}
		}
		if(can){
			std::cout << "YES" << std::endl;
		}else{
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}

/*
1051. Pop Sequence (25)
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
Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:

Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

Output Specification:

For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
Sample Output:
YES
NO
NO
YES
NO
*/
