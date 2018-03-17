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

inline int str2num(const std::string &str){
	return str[0]*10000000 + str[1]*10000 + str[2]*10 + (str[3] - '0');
}

inline std::string num2str(int num){
	std::string str;
	str.push_back(num / 10000000);
	num = num % 10000000;
	str.push_back(num / 10000);
	num = num % 10000;
	str.push_back(num / 10);
	num = num % 10;
	str.push_back(num + '0');
	return str;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n,k;
	std::cin >> n >> k;
	std::map<int,std::set<int>> map;
	int id,t;
	std::string str;
	for(int i=0;i<k;i++){
		std::cin >> id >> t;
		for(int j=0;j<t;j++){
			std::cin >> str;
			map[str2num(str)].insert(id);
		}
	}
	std::stringstream ss;
	for(int i=0;i<n;i++){
		std::cin >> str;
		auto &set = map[str2num(str)];
		ss << str << ' ' << set.size();
		for(auto &item:set){
			ss << ' ' << item;
		}
		ss << std::endl;
	}
	std::cout << ss.str();
	return 0;
}
/*
1039. Course List for Student (25)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Zhejiang University has 40000 students and provides 2500 courses. Now given the student name lists of all the courses, you are supposed to output the registered course list for each student who comes for a query.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=40000), the number of students who look for their course lists, and K (<=2500), the total number of courses. Then the student name lists are given for the courses (numbered from 1 to K) in the following format: for each course i, first the course index i and the number of registered students Ni (<= 200) are given in a line. Then in the next line, Ni student names are given. A student name consists of 3 capital English letters plus a one-digit number. Finally the last line contains the N names of students who come for a query. All the names and numbers in a line are separated by a space.

Output Specification:

For each test case, print your results in N lines. Each line corresponds to one student, in the following format: first print the student's name, then the total number of registered courses of that student, and finally the indices of the courses in increasing order. The query results must be printed in the same order as input. All the data in a line must be separated by a space, with no extra space at the end of the line.

Sample Input:
11 5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9
Sample Output:
ZOE1 2 4 5
ANN0 3 1 2 5
BOB5 5 1 2 3 4 5
JOE4 1 2
JAY9 4 1 2 4 5
FRA8 3 2 4 5
DON2 2 4 5
AMY7 1 5
KAT3 3 2 4 5
LOR6 4 1 2 4 5
NON9 0
*/
