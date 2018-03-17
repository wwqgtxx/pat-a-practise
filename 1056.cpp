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
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int np,gp;
	std::cin >> np >> gp;
	std::vector<int> datas(np);
	for(int i=0;i<np;i++){
		std::cin >> datas[i];
	}
	std::vector<int> groups(np);
	for(int i=0;i<np;i++){
		std::cin >> groups[i];
	}
	std::vector<int> result(np);
	std::vector<int> new_groups;
	while(groups.size()>1){
		int size = groups.size();
		int group = size/gp;
		if(size%gp>0){
			group++;
		}
		new_groups.clear();
		new_groups.resize(group);
		for(int i=0;i<group;i++){
			auto begin = groups.begin()+i*gp;
			auto end = std::min(groups.begin()+i*gp+gp,groups.end());
			int max_value = -1;
			int max_data;
			auto it = begin;
			while(it!=end){
//				std::cout << *it << ' ';
				if(datas[*it]>max_value){
					max_data = *it;
					max_value = datas[max_data];
				}
				result[*it] = group+1;
				it++;
			}
//			std::cout << std::endl;
			new_groups[i] = max_data;
		}
		groups.swap(new_groups);
	}
	if(groups.size() == 1){
		result[groups[0]] = 1;
	}
	for(auto it=result.begin();it!=result.end();it++){
		if(it!=result.begin()){
			std::cout << ' ';
		}
		std::cout << *it;
	}
	std::cout << std::endl;
	return 0;
}

/*
1056. Mice and Rice (25)
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
Mice and Rice is the name of a programming contest in which each programmer must write a piece of code to control the movements of a mouse in a given map. The goal of each mouse is to eat as much rice as possible in order to become a FatMouse.

First the playing order is randomly decided for NP programmers. Then every NG programmers are grouped in a match. The fattest mouse in a group wins and enters the next turn. All the losers in this turn are ranked the same. Every NG winners are then grouped in the next match until a final winner is determined.

For the sake of simplicity, assume that the weight of each mouse is fixed once the programmer submits his/her code. Given the weights of all the mice and the initial playing order, you are supposed to output the ranks for the programmers.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: NP and NG (<= 1000), the number of programmers and the maximum number of mice in a group, respectively. If there are less than NG mice at the end of the player's list, then all the mice left will be put into the last group. The second line contains NP distinct non-negative numbers Wi (i=0,...NP-1) where each Wi is the weight of the i-th mouse respectively. The third line gives the initial playing order which is a permutation of 0,...NP-1 (assume that the programmers are numbered from 0 to NP-1). All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the final ranks in a line. The i-th number is the rank of the i-th programmer, and all the numbers must be separated by a space, with no extra space at the end of the line.

Sample Input:
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3
Sample Output:
5 5 5 2 5 5 5 3 1 3 5

*/
