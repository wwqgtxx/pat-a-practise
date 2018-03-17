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
	return str[0]*1000000 + str[1]*1000 + str[2];
}

inline std::string num2str(const std::string &str){
	return str;
}

inline std::string num2str(int num){
	std::string str;
	str.push_back(num / 1000000);
	num = num % 1000000;
	str.push_back(num / 1000);
	num = num % 1000;
	str.push_back(num);
	return str;
}


template<class _t2>
const std::string& find(const std::string &str,_t2 &father){
	auto &tmp = father[str];
	if(tmp.empty()){
		return str;
	}else{
		tmp = find(tmp,father);
		return tmp;
	}
}

template<class _t2>
const int& find(const int &str,_t2 &father){
	auto &tmp = father[str];
	if(tmp == 0){
		return str;
	}else{
		tmp = find(tmp,father);
		return tmp;
	}
}

template<class _t1,class _t2>
bool join(const _t1 &str1,const _t1 &str2,_t2 &father){
	auto &f1 = find(str1,father);
	auto &f2 = find(str2,father);
	if(f1 != f2){
		father[f2] = f1;
		return true;
	}else{
		return false;
	}
}

//#define USE_INT_STR

#ifdef USE_INT_STR
	typedef int str_t;
#else
	typedef std::string str_t;
#endif

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n,k;
	std::cin >> n >> k;
	std::string str1,str2;
	int s1,s2;
	int time;
	std::map<str_t,str_t> father;
	std::map<str_t,std::map<str_t,int>> map;
	for(int i=0;i<n;i++){
		std::cin >> str1 >> str2 >> time;
#ifdef USE_INT_STR
		s1 = str2num(str1);
		s2 = str2num(str2);
		map[s1][s2] += time;
		map[s2][s1] += time;
		join(s1,s2,father);
#else
		map[str1][str2] += time;
		map[str2][str1] += time;
		join(str1,str2,father);
#endif
	}
	std::map<str_t,std::vector<str_t>> group;
	for(auto &i1 : map){
		auto &f1 = find(i1.first,father);
		auto &vec = group[f1];
		vec.emplace_back(i1.first);
	}
////	std::cout << group.size() << std::endl;
	std::set<std::pair<str_t,int>> result;
	for(auto &i1 : group){
		auto &vec = i1.second;
		if(vec.size() <= 2){
			continue;
		}
		int total = 0;
		auto max_name = vec[0];
		int max_time=-1;
		for(auto &i2 : vec){
			int total2 = 0;
			for(auto &t3: map[i2]){
				total += t3.second;
				total2 += t3.second;
			}
			if(total2 > max_time){
				max_time = total2;
				max_name = i2;
			}
//			std::cout << i2 << ' ';
//			std::cout << total2 << ' ';
		}
		total /= 2;
//		std::cout << " | " << total << ' ' << max_name << std::endl;
		if(total > k){
			result.emplace(max_name,vec.size());
		}
	}
	std::cout << result.size() << std::endl;
	for(auto &i : result){
		std::cout << num2str(i.first) << ' ' << i.second << std::endl;
	}
	return 0;
} 

/*
1034. Head of a Gang (30)
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
One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight threshold, respectively. Then N lines follow, each in the following format:

Name1 Name2 Time

where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.

Output Specification:

For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.

Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3
Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0
*/ 
