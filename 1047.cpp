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
	std::vector<std::vector<int>> vec(k+1);
	std::string str;
	int t1,t2,t3;
	for(int i=0;i<n;i++){
		std::cin >> str >> t1;
		t3 = str2num(str);
		for(int j=0;j<t1;j++){
			std::cin >> t2;
			vec[t2].emplace_back(t3);
		}
	}
	std::stringstream ss;
	for(int i=1;i<=k;i++){
		auto &v = vec[i];
		std::sort(v.begin(),v.end());
		ss << i << ' ' << v.size() << std::endl;
		for(auto &item:v){
			ss << num2str(item) << std::endl;
		}
	}
	std::cout << ss.str();
	return 0;
}

/*
1047. Student List for Course (25)
时间限制
400 ms
内存限制
64000 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Zhejiang University has 40000 students and provides 2500 courses. Now given the registered course list of each student, you are supposed to output the student name lists of all the courses.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=40000), the total number of students, and K (<=2500), the total number of courses. Then N lines follow, each contains a student's name (3 capital English letters plus a one-digit number), a positive number C (<=20) which is the number of courses that this student has registered, and then followed by C course numbers. For the sake of simplicity, the courses are numbered from 1 to K.

Output Specification:

For each test case, print the student name lists of all the courses in increasing order of the course numbers. For each course, first print in one line the course number and the number of registered students, separated by a space. Then output the students' names in alphabetical order. Each name occupies a line.

Sample Input:
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5
Sample Output:
1 4
ANN0
BOB5
JAY9
LOR6
2 7
ANN0
BOB5
FRA8
JAY9
JOE4
KAT3
LOR6
3 1
BOB5
4 7
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
5 9
AMY7
ANN0
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
*/
