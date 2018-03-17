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

struct Data{
	std::shared_ptr<std::tuple<int,int,std::string>> data;
	Data(const int &net,const int &age,const std::string &name){
		data = std::make_shared<std::tuple<int,int,std::string>>(net,age,name);
	}
	
	Data(const Data &d):data(d.data){
//		std::cout << "copy" << std::endl;
	}
	
	Data(Data &&d):data(d.data){
//		std::cout << "move" << std::endl;
	}
	
//	~Data(){
//		std::cout << "delete" << std::endl;
//	}
	
	void operator = (const Data &d){
//		std::cout << "=" << std::endl;
		data = d.data;
	}
	
	bool operator < (const Data &d){
		return *data < *d.data;
	}
	
	int& net(){
		return std::get<0>(*data);
	}
	
	int& age(){
		return std::get<1>(*data);
	}
	
	std::string& name(){
		return std::get<2>(*data);
	}
};

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n,k;
	std::cin >> n >> k;
	std::string name;
	int age,net;
	std::vector<std::vector<Data>> vecs(201);
	for(int i=0;i<n;i++){
		std::cin >> name >> age >> net;
		auto &vec = vecs[age];
		vec.emplace_back(-net,age,name);
		std::push_heap(vec.begin(),vec.end());
		if(vec.size()>100){
			std::pop_heap(vec.begin(),vec.end());
			vec.pop_back();
		}
	} 
	std::stringstream ss;
	int m,min,max;
	std::vector<Data> vec;
	for(int i=1;i<=k;i++){
		std::cin >> m >> min >> max;
		ss << "Case #" << i << ':' << std::endl;
		vec.clear();
		for(int j=min;j<=max;j++){
			for(auto &item:vecs[j]){
				vec.emplace_back(item);
			}
		}
		if(vec.empty()){
			ss << "None" << std::endl;
		}else{
			auto dis = std::min(m,int(vec.size()));
			std::partial_sort(vec.begin(),vec.begin()+dis,vec.end());
			auto begin2 = vec.begin();
			auto end2 = vec.begin()+dis;
			while(begin2 != end2){
				ss << begin2->name() << ' '
				   << begin2->age() << ' '
				   << -(begin2->net())
				   << std::endl;
				++begin2;
			}
		}
	
	}
	std::cout << ss.str();
} 

/*
1055. The World's Richest (25)
时间限制
400 ms
内存限制
128000 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Forbes magazine publishes every year its list of billionaires based on the annual ranking of the world's wealthiest people. Now you are supposed to simulate this job, but concentrate only on the people in a certain range of ages. That is, given the net worths of N people, you must find the M richest people in a given range of their ages.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=105) - the total number of people, and K (<=103) - the number of queries. Then N lines follow, each contains the name (string of no more than 8 characters without space), age (integer in (0, 200]), and the net worth (integer in [-106, 106]) of a person. Finally there are K lines of queries, each contains three positive integers: M (<= 100) - the maximum number of outputs, and [Amin, Amax] which are the range of ages. All the numbers in a line are separated by a space.

Output Specification:

For each query, first print in a line "Case #X:" where X is the query number starting from 1. Then output the M richest people with their ages in the range [Amin, Amax]. Each person's information occupies a line, in the format

Name Age Net_Worth
The outputs must be in non-increasing order of the net worths. In case there are equal worths, it must be in non-decreasing order of the ages. If both worths and ages are the same, then the output must be in non-decreasing alphabetical order of the names. It is guaranteed that there is no two persons share all the same of the three pieces of information. In case no one is found, output "None".
Sample Input:
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50
Sample Output:
Case #1:
Alice 18 88888
Billy 24 5888
Bob_Volk 24 5888
Dobby 24 5888
Case #2:
Joe_Mike 32 3222
Zoe_Bill 35 2333
Williams 30 -22
Case #3:
Anny_Cin 95 999999
Michael 5 300000
Alice 18 88888
Cindy 76 76000
Case #4:
None
*/
