#include<vector>
#include<iostream> 
#include<algorithm>

template<class T1,class T2>
void dfs(const int &begin,T1 &map,T2 &visit){
//	std::cout << "dfs:"<< begin << std::endl;
	visit[begin] = 1;
	auto &item = map[begin];
	for(auto it=item.begin();it!=item.end();it++){
		if(!visit[*it]){
			dfs(*it,map,visit);
		}
	}
}

int main(){
	int n,m,k;
	std::cin >> n >> m >> k;
	n++;
	std::vector<std::vector<int>> map(n);
	std::vector<int> cities(k);
	for(int i=0;i<m;i++){
		int a,b;
		std::cin >> a >> b;
		map[a].emplace_back(b);
		map[b].emplace_back(a);
	}
	for(int i=0;i<k;i++){
		int a;
		std::cin >> a;
		cities[i] = a;
	}
	std::vector<int> visit(n,0);
	for(int i=0;i<k;i++){
		int &a = cities[i];
		std::fill(visit.begin(),visit.end(),0);
		visit[a] = true;
		int num=0;
		for(int j=1;j<n;j++){
			if(!visit[j]){
				dfs(j,map,visit);
				num++;
			}
		}
		num--;
		std::cout << num << std::endl;
	}
	return 0;
}

/*
1013. Battle Over Cities (25)
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
It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting city1-city2 and city1-city3. Then if city1 is occupied by the enemy, we must have 1 highway repaired, that is the highway city2-city3.

Input

Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.

Output

For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.

Sample Input
3 2 3
1 2
1 3
1 2 3
Sample Output
1
0
0
*/
