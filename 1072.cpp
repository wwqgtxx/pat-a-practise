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

const int INF = 1e6;

std::vector<std::vector<std::pair<int,int>>> vec;
std::vector<int> dis;
std::vector<char> vis;
int n,m,k,ds;

inline int str2int(const std::string &s){
	int id;
	if(s[0] == 'G'){
		id = n;
		if(s.size() == 3){
			id += 10;
		}else{
			id += s[1]-'0';
		}
	}else{
		id = ::atoi(s.c_str());
	}
	
	return id;
}

void dijkstra(const int &begin){
	typedef std::pair<int,int> pii;
	std::priority_queue<pii,std::vector<pii>,std::greater<pii>> queue;
	std::fill(dis.begin(),dis.end(),INF);
	std::fill(vis.begin(),vis.end(),0);
	queue.emplace(0,begin);
	while(!queue.empty()){
		auto pi = queue.top();
		queue.pop();
		if(vis[pi.second]){
			continue;
		}
		vis[pi.second] = true;
		for(auto &item:vec[pi.second]){
			int &to = item.first;
			int new_dis = item.second + pi.first;
			if(new_dis < dis[to]){
				dis[to] = new_dis;
				queue.emplace(new_dis,to);
			}
		}
	}
}

int main(){
	std::cin >> n >> m >> k >> ds;
	vec.resize(n+1+m);
	dis.resize(n+1+m);
	vis.resize(n+1+m);
	std::string str;
	int p1,p2,d;
	for(int i=0;i<k;i++){
		std::cin >> str;
		p1 = str2int(str);
		std::cin >> str;
		p2 = str2int(str);
		std::cin >> d;
		vec[p1].emplace_back(p2,d);
		vec[p2].emplace_back(p1,d);
	}
	typedef std::tuple<double,double,int> _r_t;
	std::vector<_r_t> result;
	for(int i=1;i<=m;i++){
		dijkstra(n+i);
		bool is_ok = true;
		int min_dis = INF;
		double sum_dis = 0;
		for(int j=1;j<=n;j++){
			auto &dj = dis[j];
			if(dj > ds){
				is_ok = false;
				break;
			}
			min_dis = std::min(min_dis,dj);
			sum_dis += dj;
		}
		if(is_ok){
			result.emplace_back(min_dis,sum_dis/n,i);
		}
	}
	if(result.empty()){
		std::cout << "No Solution" << std::endl;
	}else{
		int id;
		double min,avg;
		std::tie(min,avg,id) = *std::min_element(result.begin(),result.end(),[](_r_t &i1,_r_t &i2){
			if(std::get<0>(i1) != std::get<0>(i2)) {
				return std::get<0>(i1) > std::get<0>(i2);
			}
			if(std::get<1>(i1) != std::get<1>(i2)) {
				return std::get<1>(i1) < std::get<1>(i2);
			}
			return std::get<2>(i1) < std::get<2>(i2);
		});	
		std::cout << 'G' << id << std::endl;
		std::cout << std::fixed << std::setprecision(1) << min << ' ';
		std::cout << std::fixed << std::setprecision(1) << avg + 1e-6 << std::endl;
	}
	
} 

/*
1072. Gas Station (30)
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
A gas station has to be built at such a location that the minimum distance between the station and any of the residential housing is as far away as possible. However it must guarantee that all the houses are in its service range.

Now given the map of the city and several candidate locations for the gas station, you are supposed to give the best recommendation. If there are more than one solution, output the one with the smallest average distance to all the houses. If such a solution is still not unique, output the one with the smallest index number.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive integers: N (<= 103), the total number of houses; M (<= 10), the total number of the candidate locations for the gas stations; K (<= 104), the number of roads connecting the houses and the gas stations; and DS, the maximum service range of the gas station. It is hence assumed that all the houses are numbered from 1 to N, and all the candidate locations are numbered from G1 to GM.

Then K lines follow, each describes a road in the format
P1 P2 Dist
where P1 and P2 are the two ends of a road which can be either house numbers or gas station numbers, and Dist is the integer length of the road.

Output Specification:

For each test case, print in the first line the index number of the best location. In the next line, print the minimum and the average distances between the solution and all the houses. The numbers in a line must be separated by a space and be accurate up to 1 decimal place. If the solution does not exist, simply output “No Solution”.

Sample Input 1:
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
Sample Output 1:
G1
2.0 3.3
Sample Input 2:
2 1 2 10
1 G1 9
2 G1 20
Sample Output 2:
No Solution

*/
