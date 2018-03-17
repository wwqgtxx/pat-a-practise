#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<queue>

const int INF = 1e6;

int c,n,s,m;
int cc;
std::vector<std::vector<int>> g;
std::vector<int> bikes;

std::vector<int> vis;
std::vector<int> dis;
std::vector<std::vector<int>> pre;

void dijkstra(const int &begin){
	typedef std::pair<int,int> pii;
	std::priority_queue<pii,std::vector<pii>,std::greater<pii>> queue;
	std::fill(dis.begin(),dis.end(),INF);
	std::fill(vis.begin(),vis.end(),0);
	queue.emplace(0,begin);
	while(!queue.empty()){
		auto pi = queue.top();
		queue.pop();
//		std::cout << "get:<" << pi.first << ',' << pi.second << '>' << std::endl;
		if(vis[pi.second]){
			continue;
		}
		vis[pi.second] = 1;
		auto &gg = g[pi.second];
		for(int i=0;i<gg.size();i++){
//			std::cout << "test:" << i << std::endl;
			if(!vis[i]){
				int tmp = gg[i]+pi.first;
				if(tmp<dis[i]){
					dis[i] = tmp;
					pre[i].clear();
					queue.emplace(tmp,i);
				}
				if(tmp<=dis[i]){
					pre[i].emplace_back(pi.second);
				}
			}
		} 
	}
}

void dfs(const int &begin,std::vector<int> &rode,int &min_value,int &min_state,std::vector<int> &min_rode){
//	std::cout << "visit:" << begin << std::endl;
	vis[begin] = 1;
	rode.emplace_back(begin);
	auto &pre1 = pre[begin];
	if(pre1.empty()){
		int need_num = 0;
		int now_state = 0;
		for(auto it=++rode.rbegin();it!=rode.rend();it++){
//			std::cout << "->";
			int &num = bikes[*it];
			if(num > cc){
				now_state += num - cc;
			}else if(num < cc){
				int need = cc-num;
				if(need>now_state){
					need_num += need-now_state;
					now_state = 0;
				}else{
					now_state -= need;
				}
			}
//			std::cout << *it;
			
//			std::cout << "need_num:" << need_num << " now_state:" << now_state << std::endl;;
			
		}
//		std::cout << std::endl;
//		std::cout << need_num << ',' << now_state << std::endl;
		if(need_num < min_value){
			min_value = need_num;
			min_state = now_state;
			min_rode = rode;
		}else if(need_num == min_value){
			if(now_state < min_state){
				min_value = need_num;
				min_state = now_state;
				min_rode = rode;
			}
		}
	}else{
		for(auto &i : pre1){
			if(!vis[i]){
				dfs(i,rode,min_value,min_state,min_rode);
			}
		}
	}
	
	rode.pop_back();
	vis[begin] = 0;
}

int main(){
	std::cin >> c >> n >> s >> m;
	cc = c/2;
	g.resize(n+1,std::vector<int>(n+1,INF));
	bikes.resize(n+1);
	vis.resize(n+1);
	pre.resize(n+1);
	dis.resize(n+1);
	for(int i=1;i<=n;i++){
		std::cin >> bikes[i];
	}
	for(int i=0;i<m;i++){
		int si,sj,tij;
		std::cin >> si >> sj >> tij;
		g[si][sj]=tij;
		g[sj][si]=tij;
	}
	dijkstra(0);
	std::vector<int> rode,min_rode;
	std::fill(vis.begin(),vis.end(),0);
	int min_value=INF;
	int min_state=INF;
	dfs(s,rode,min_value,min_state,min_rode);
	std::cout << min_value << ' ';
	for(auto it=min_rode.rbegin();it!=min_rode.rend();it++){
		if(it!=min_rode.rbegin()){
			std::cout << "->";
		}
		std::cout << *it;		
	}
	std::cout << ' ' << min_state << std::endl;
	return 0;
} 
/*
1018. Public Bike Management (30)
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
There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent a bike at any station and return it to any other stations in the city.

The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect condition if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. And more, all the stations on the way will be adjusted as well.

When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.


Figure 1
Figure 1 illustrates an example. The stations are represented by vertices and the roads correspond to the edges. The number on an edge is the time taken to reach one end station from another. The number written inside a vertex S is the current number of bikes stored at S. Given that the maximum capacity of each station is 10. To solve the problem at S3, we have 2 different shortest paths:

1. PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S1 and then take 5 bikes to S3, so that both stations will be in perfect conditions.

2. PBMC -> S2 -> S3. This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 numbers: Cmax (<= 100), always an even number, is the maximum capacity of each station; N (<= 500), the total number of stations; Sp, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. The second line contains N non-negative numbers Ci (i=1,...N) where each Ci is the current number of bikes at Si respectively. Then M lines follow, each contains 3 numbers: Si, Sj, and Tij which describe the time Tij taken to move betwen stations Si and Sj. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print your results in one line. First output the number of bikes that PBMC must send. Then after one space, output the path in the format: 0->S1->...->Sp. Finally after another space, output the number of bikes that we must take back to PBMC after the condition of Sp is adjusted to perfect.

Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The judge's data guarantee that such a path is unique.

Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0
*/
