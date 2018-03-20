#include<cstdio>
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::map<std::string,std::pair<double,int>> map;
	int n;
	std::cin >> n;
	std::string id,school;
	int score;
	for(int i=0;i<n;i++){
		std::cin >> id >> score >> school;
		for(auto &c:school){
			c = :: tolower(c);
		}
		auto &pair = map[school];
		pair.second++;
		switch(id[0]){
			case 'T':{
				pair.first += score * 1.5;
				break;
			}
			case 'A':{
				pair.first += score;
				break;
			}
			case 'B':{
				pair.first += score / 1.5;
				break;
			}
				
		}
		
	}
	std::cout << map.size() << std::endl;
	std::set<std::tuple<int,int,std::string>> set;
	for(auto &item:map){
//		std::cout << item.first << ' ' << item.second.first << ' ' << item.second.second << std::endl;
		set.emplace(-int(item.second.first),item.second.second,item.first);
	}
	int last_score = -1;
	int last_num = 0;
	int num = 0;
	for(auto &item:set){
		score = -std::get<0>(item);
		num++;
		if(last_score != score){
			last_score = score;
			last_num = num;
		}
		std::cout << last_num << ' ' << std::get<2>(item) << ' ' << score << ' ' << std::get<1>(item) << std::endl;
	}
}

/*
1141. PAT Ranking of Institutions (25)
时间限制
500 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
After each PAT, the PAT Center will announce the ranking of institutions based on their students' performances. Now you are asked to generate the ranklist.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=105), which is the number of testees. Then N lines follow, each gives the information of a testee in the following format:

ID Score School

where "ID" is a string of 6 characters with the first one representing the test level: "B" stands for the basic level, "A" the advanced level and "T" the top level; "Score" is an integer in [0, 100]; and "School" is the institution code which is a string of no more than 6 English letters (case insensitive). Note: it is guaranteed that "ID" is unique for each testee.

Output Specification:

For each case, first print in a line the total number of institutions. Then output the ranklist of institutions in nondecreasing order of their ranks in the following format:

Rank School TWS Ns

where "Rank" is the rank (start from 1) of the institution; "School" is the institution code (all in lower case); "TWS" is the total weighted score which is defined to be the integer part of "ScoreB/1.5 + ScoreA + ScoreT*1.5", where "ScoreX" is the total score of the testees belong to this institution on level X; and "Ns" is the total number of testees who belong to this institution.

The institutions are ranked according to their TWS. If there is a tie, the institutions are supposed to have the same rank, and they shall be printed in ascending order of Ns. If there is still a tie, they shall be printed in alphabetical order of their codes.

Sample Input:
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
Sample Output:
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2

*/
