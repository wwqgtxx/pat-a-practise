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

struct Rank{
	static int K;
	int uid;
	std::shared_ptr<std::vector<int>> data;
	int total;
	int pass;
	
	Rank(){
//		std::cout << "new" << std::endl;
		data = std::make_shared<std::vector<int>>(K,-2);
	}
	
	Rank(const Rank &rank):uid(rank.uid),data(rank.data),total(rank.total),pass(rank.pass){
//		std::cout << "copy" << std::endl;
	}
	
	Rank(Rank &&rank):uid(rank.uid),data(std::move(rank.data)),total(rank.total),pass(rank.pass){
//		std::cout << "move" << std::endl;
	}
	
//	~Rank(){
//		std::cout << "delete" << std::endl;
//	} 
	
	void operator = (const Rank &rank){
//		std::cout << "=" << std::endl;
		uid = rank.uid;
		data = rank.data;
		total = rank.total;
		pass = rank.pass;
	}
	
	void operator = (Rank &&rank){
//		std::cout << "move=" << std::endl;
		uid = rank.uid;
		data = std::move(rank.data);
		total = rank.total;
		pass = rank.pass;
	}
	
	int& operator [] (const int &i) const{
		return (*data)[i];
	}
	
	std::vector<int>::iterator begin() const{
		return data->begin();
	}
	
	std::vector<int>::iterator end() const{
		return data->end();
	}
	
	int sum(){
		int i = 0;
		for(auto &item:(*this)){
			if(item > 0){
				i += item;
			}
		}
		return i;
	}
	
	void cal(const Rank &other){
		total = 0;
		pass = 0;
		for(int i=0;i<K;i++){
			auto &item = (*this)[i];
			auto &item2 = other[i];
			if(item > 0){
				total += item;
				if(item == item2){
					++pass;
				}
			}
		}
	}
	
	bool operator < (const Rank &other){
		if(total != other.total){
			return total > other.total;
		}
		if(pass != other.pass){
			return pass > other.pass;
		}
		return uid < other.uid;
	}
};

int Rank::K = 1;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n,k,m;
	std::cin >> n >> k >> m;
	Rank::K = k;
	Rank total;
	for(int i=0;i<k;i++){
		std::cin >> total[i];
	}
	std::map<int,Rank> map;
	int uid,pid,score;
	for(int i=0;i<m;i++){
		std::cin >> uid >> pid >> score;
		--pid;
		auto &rank = map[uid];
		rank.uid = uid;
		auto &s = rank[pid];
		s = std::max(s,score);
	}
	std::vector<Rank> vec;
	vec.reserve(map.size());
	for(auto &item:map){
		auto &rank = item.second;
		rank.cal(total);
		vec.emplace_back(std::move(rank));
	}
	std::sort(vec.begin(),vec.end());
	int last_total = -1;
	int last_index = 0;
	int index = 0;
	
	std::stringstream ss;
	for(auto &rank:vec){
		++index;
		if(rank.total != last_total){
			last_total = rank.total;
			last_index = index;
		}
		ss.str("");
		ss.clear();
		ss << last_index << ' ';
		ss << std::setfill('0') << std::setw(5) << rank.uid ;
		ss << ' ' << rank.total;
//		ss << ' ' << rank.pass;
		bool can_print = false;
		for(auto &item2:rank){
			if(item2 == -2){
				ss << " -";
			}else if(item2 == -1){
				ss << " 0";
			}else{
				ss << ' ' << item2;
				can_print = true;
			}
		}
		if(can_print || vec.size() == 1){
			std::cout << ss.str() << std::endl;
		}	
	}
	return 0;
}
/*
1075. PAT Judge (25)
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
The ranklist of PAT is generated from the status list, which shows the scores of the submittions. This time you are supposed to generate the ranklist for PAT.

Input Specification:

Each input file contains one test case. For each case, the first line contains 3 positive integers, N (<=104), the total number of users, K (<=5), the total number of problems, and M (<=105), the total number of submittions. It is then assumed that the user id's are 5-digit numbers from 00001 to N, and the problem id's are from 1 to K. The next line contains K positive integers p[i] (i=1, ..., K), where p[i] corresponds to the full mark of the i-th problem. Then M lines follow, each gives the information of a submittion in the following format:

user_id problem_id partial_score_obtained

where partial_score_obtained is either -1 if the submittion cannot even pass the compiler, or is an integer in the range [0, p[problem_id]]. All the numbers in a line are separated by a space.

Output Specification:

For each test case, you are supposed to output the ranklist in the following format:

rank user_id total_score s[1] ... s[K]

where rank is calculated according to the total_score, and all the users with the same total_score obtain the same rank; and s[i] is the partial score obtained for the i-th problem. If a user has never submitted a solution for a problem, then "-" must be printed at the corresponding position. If a user has submitted several solutions to solve one problem, then the highest score will be counted.

The ranklist must be printed in non-decreasing order of the ranks. For those who have the same rank, users must be sorted in nonincreasing order according to the number of perfectly solved problems. And if there is still a tie, then they must be printed in increasing order of their id's. For those who has never submitted any solution that can pass the compiler, or has never submitted any solution, they must NOT be shown on the ranklist. It is guaranteed that at least one user can be shown on the ranklist.

Sample Input:
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
Sample Output:
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -

*/
