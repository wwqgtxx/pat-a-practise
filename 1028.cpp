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

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n,c;
	std::cin >> n >> c;
	int id;
	std::string name;
	int grade;
	std::stringstream ss;
	switch(c){
		case 1:{
			typedef std::tuple<int,std::string,int> _t;
			std::set<_t> set;
			for(int i=0;i<n;i++){
				std::cin >> id >> name >> grade;
				set.emplace(id,std::move(name),grade);
			}
			for(auto &i:set){
				ss << std::setfill('0') << std::setw(6)
						  << std::get<0>(i) << ' '
						  << std::get<1>(i) << ' '
						  << std::get<2>(i) << std::endl;
			}
			break;
		}
		case 2:{
			typedef std::tuple<std::string,int,int> _t;
			std::set<_t> set;
			for(int i=0;i<n;i++){
				std::cin >> id >> name >> grade;
				set.emplace(std::move(name),id,grade);
			}
			for(auto &i:set){
				ss << std::setfill('0') << std::setw(6)
						  << std::get<1>(i) << ' '
						  << std::get<0>(i) << ' '
						  << std::get<2>(i) << std::endl;
			}
			break;
		}
		case 3:{
			typedef std::tuple<int,int,std::string> _t;
			std::set<_t> set;
			for(int i=0;i<n;i++){
				std::cin >> id >> name >> grade;
				set.emplace(grade,id,std::move(name));
			}
			for(auto &i:set){
				ss << std::setfill('0') << std::setw(6)
						  << std::get<1>(i) << ' '
						  << std::get<2>(i) << ' '
						  << std::get<0>(i) << std::endl;
			}
			break;
		}
	}
	std::cout << ss.str();
} 

/*
1028. List Sorting (25)
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
Excel can sort records according to any column. Now you are supposed to imitate this function.

Input

Each input file contains one test case. For each case, the first line contains two integers N (<=100000) and C, where N is the number of records and C is the column that you are supposed to sort the records with. Then N lines follow, each contains a record of a student. A student's record consists of his or her distinct ID (a 6-digit number), name (a string with no more than 8 characters without space), and grade (an integer between 0 and 100, inclusive).

Output

For each test case, output the sorting result in N lines. That is, if C = 1 then the records must be sorted in increasing order according to ID's; if C = 2 then the records must be sorted in non-decreasing order according to names; and if C = 3 then the records must be sorted in non-decreasing order according to grades. If there are several students who have the same name or grade, they must be sorted according to their ID's in increasing order.

Sample Input 1
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
Sample Output 1
000001 Zoe 60
000007 James 85
000010 Amy 90
Sample Input 2
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
Sample Output 2
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
Sample Input 3
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
Sample Output 3
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
*/
