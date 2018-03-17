#include<cstdio>
#include<vector>
#include<queue>
#include<map>

const int INF = 1e6;

int n,m,c1,c2;
std::vector<int> mens;
std::vector<std::vector<int> > costs;
std::vector<int> dis;
std::vector<int> teams;
std::vector<int> nums;
std::vector<bool> vis;

void dijkstra(){
	vis.resize(n,false);
	teams.resize(n,0);
	nums.resize(n,0);
	dis.resize(n,INF);
	dis[c1] = 0;
	teams[c1] = mens[c1];
	nums[c1] = 1;
	
	typedef std::pair<int,int> pii;
	std::priority_queue<pii,std::vector<pii>,std::greater<pii> > queue;
	queue.push(std::make_pair(dis[c1],c1));
	
	while(!queue.empty()){
		pii pi = queue.top();
		queue.pop();
		
		int &k=pi.second;
		int &min = pi.first;
		if(vis[k]){
			continue;
		}
		vis[k] = true;
		for(int j=0;j<n;j++){
			if(!vis[j]){
				if(min+costs[k][j] < dis[j]){
					dis[j] = min+costs[k][j];
					teams[j] = teams[k] + mens[j];
					nums[j] = nums[k];
					queue.push(std::make_pair(dis[j],j));
				}else if(min+costs[k][j] == dis[j]){
					teams[j] = std::max(teams[k] + mens[j],teams[j]);
					nums[j] += nums[k];
				}
			}
			
		}
	}
	
}

//void dijkstra(){
//	vis.resize(n,false);
//	teams.resize(n,0);
//	nums.resize(n,0);
//	dis.resize(n,INF);
//	dis[c1] = 0;
//	teams[c1] = mens[c1];
//	nums[c1] = 1;
//	for(int i=0;i<n;i++){
//		int min = INF;
//		int k=0;
//		for(int j=0;j<n;j++){
//			if(!vis[j] && dis[j]<min){
//				min = dis[j];
//				k = j;
//			}
//		}
//		vis[k] = true;
//		for(int j=0;j<n;j++){
//			if(!vis[j]){
//				if(min+costs[k][j] < dis[j]){
//					dis[j] = min+costs[k][j];
//					teams[j] = teams[k] + mens[j];
//					nums[j] = nums[k];
//				}else if(min+costs[k][j] == dis[j]){
//					teams[j] = std::max(teams[k] + mens[j],teams[j]);
//					nums[j] += nums[k];
//				}
//			}
//			
//		}
//	}
//	
//}

int main(){
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	mens.resize(n);
	for(int i=0;i<n;i++){
		scanf("%d",&mens[i]);
	}
	costs.resize(n,std::vector<int>(n,INF));
	int t1,t2,t3;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		costs[t1][t2] = costs[t2][t1] = t3;
	}
	dijkstra();
	printf("%d %d",nums[c2],teams[c2]);
	return 0;
}

/*
1003. Emergency (25)
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
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
*/ 
