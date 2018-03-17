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

const int INF = 1e6;

std::vector<std::vector<std::tuple<int,int,int>>> g;
std::vector<int> dis;
std::vector<int> cost;
std::vector<char> vis;
std::vector<std::vector<int>> pre;

void dijkstra(const int &begin){
	typedef std::tuple<int,int,int> pii;
	std::priority_queue<pii,std::vector<pii>,std::greater<pii>> q;
	q.emplace(0,0,begin);
	std::fill(vis.begin(),vis.end(),0);
	std::fill(dis.begin(),dis.end(),INF);
	std::fill(cost.begin(),cost.end(),INF);
	while(!q.empty()){
		int city1,dis1,cost1;
		std::tie(dis1,cost1,city1) = q.top();
//		std::cout << "get:" << city1 << std::endl;
		q.pop();
		if(vis[city1]){
			continue;
		}
		vis[city1] = true;
//		std::cout << "size:" << g[city1].size() << std::endl;
		for(auto &t:g[city1]){
			int to,dis2,cost2;
			std::tie(to,dis2,cost2) = t;
//			std::cout << "test:" << to << std::endl;
			if(!vis[to]){
				int new_d = dis1+dis2;
				int &old_d = dis[to];
				int new_c = cost1+cost2;
				int &old_c = cost[to];
				if(new_d < old_d){
					old_d = new_d;
					old_c = new_c;
					pre[to] = pre[city1];
					pre[to].emplace_back(city1);
					q.emplace(new_d,new_c,to);
				}else if(new_d == old_d){
					if(new_c < old_c){
						old_c = new_c;
						pre[to] = pre[city1];
						pre[to].emplace_back(city1);
					}
				}
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	int n,m,s,d;
	std::cin >> n >> m >> s >> d;
	g.resize(n);
	dis.resize(n);
	cost.resize(n);
	vis.resize(n);
	pre.resize(n);
	int t1,t2,t3,t4;
	for(int i=0;i<m;i++){
		std::cin >> t1 >> t2 >> t3 >> t4;
		g[t1].emplace_back(t2,t3,t4);
		g[t2].emplace_back(t1,t3,t4);
	}
	dijkstra(s);
	std::copy(pre[d].begin(),pre[d].end(),std::ostream_iterator<int>(std::cout," "));
	std::cout << d << ' ';
	std::cout << dis[d] << ' ' << cost[d] << std::endl;
	return 0;
} 

/*
1030. Travel Plan (30)
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
A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.

Input Specification:

Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:

City1 City2 Distance Cost

where the numbers are all integers no more than 500, and are separated by a space.

Output Specification:

For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.

Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output
0 2 3 3 40
*/
