#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
#include<sstream>

template<class T>
int get_nrd(T &t,const int &grade){
	int nrd = 0;
	for(auto it = t.begin();it!=t.end();it++){
		if(it->first == grade){
			nrd++;
			break;
		}else{
			nrd += it->second.size();
		}
	}
	return nrd;
}

int main(){
	int n,m;
	std::cin >> n >> m;
	int id,cc,cm,ce,ca;
	std::map<int,std::vector<int>,std::greater<int>> mc,mm,me,ma;
	std::map<int,std::tuple<int,int,int,int>> map;
	for(int i=0;i<n;i++){
		std::cin >> id >> cc >> cm >> ce;
		ca = cc+cm+ce;
		mc[cc].push_back(id);
		mm[cm].push_back(id);
		me[ce].push_back(id);
		ma[ca].push_back(id);
		map.insert(std::make_pair(id,std::make_tuple(cc,cm,ce,ca)));
	}
	std::stringstream ss;
	for(int i=0;i<m;i++){
		std::cin >> id;
		auto map_it = map.find(id);
		if(map_it == map.end()){
			ss << "N/A" << std::endl;
		}else{
			auto &tuple = map_it->second;
			std::tie(cc,cm,ce,ca) = tuple;
//			cc = std::get<0>(tuple);
//			cm = std::get<1>(tuple);
//			ce = std::get<2>(tuple);
//			ca = std::get<3>(tuple);
			
			cc = get_nrd(mc,cc);
			cm = get_nrd(mm,cm);
			ce = get_nrd(me,ce);
			ca = get_nrd(ma,ca);
			
			int highest = ca;
			char which = 'A';
			
			if(cc<highest){
				highest = cc;
				which = 'C';
			}
			
			if(cm<highest){
				highest = cm;
				which = 'M';
			}
			
			if(ce<highest){
				highest = ce;
				which = 'E';
			}
			
			ss << highest << ' ' << which << std::endl;
		}
	}
	std::cout << ss.str();
	return 0;
}

/*
1012. The Best Rank (25)
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
To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algebra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:

StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input

Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

Output

For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output "N/A".

Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output
1 C
1 M
1 E
1 A
3 A
N/A

*/ 
