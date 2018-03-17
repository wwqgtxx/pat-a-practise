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

int main(){
	std::set<int> set;
	std::vector<int> vec;
	int n;
	int t;
	std::cin >> n;
	for(int i=0;i<n;i++){
		std::cin >> t;
		if(t >=1 && t <= 1e4){
			auto result = set.insert(t);
			if(result.second){
				vec.push_back(t);
			}else{
				auto it = std::find(vec.begin(),vec.end(),t);
				if(it!=vec.end()){
					vec.erase(it);
				}
			}
		}
	}
	if(vec.empty()){
		std::cout << "None" << std::endl;
	}else{
		std::cout << vec[0] << std::endl;
	}
}

/*
1041. Be Unique (20)
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
Being unique is so important to people on Mars that even their lottery is designed in a unique way. The rule of winning is simple: one bets on a number chosen from [1, 104]. The first one who bets on a unique number wins. For example, if there are 7 people betting on 5 31 5 88 67 88 17, then the second one who bets on 31 wins.

Input Specification:

Each input file contains one test case. Each case contains a line which begins with a positive integer N (<=105) and then followed by N bets. The numbers are separated by a space.

Output Specification:

For each test case, print the winning number in a line. If there is no winner, print "None" instead.

Sample Input 1:
7 5 31 5 88 67 88 17
Sample Output 1:
31
Sample Input 2:
5 888 666 666 888 888
Sample Output 2:
None

*/
