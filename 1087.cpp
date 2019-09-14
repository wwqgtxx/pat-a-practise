#include<cstdio>
#include<cstring>
#include<stdint.h>
#include<algorithm>
#include<set>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<queue>

struct city_name_t{
	char str[4];
	city_name_t(){
		memset(str,0,sizeof(str));
	}
	city_name_t(const char* string){
		memcpy(str,string,sizeof(str));
	}
	city_name_t(const std::string &string){
		memcpy(str,string.c_str(),sizeof(str));
	}
	city_name_t(const city_name_t &other){
		memcpy(str,other.str,sizeof(str));
	}
	city_name_t& operator = (const char* string){
		memcpy(str,string,sizeof(str));
		return *this;
	}
	city_name_t& operator = (const std::string &string){
		memcpy(str,string.c_str(),sizeof(str));
		return *this;
	}
	city_name_t& operator = (const city_name_t &other){
		memcpy(str,other.str,sizeof(str));
		return *this;
	}

	bool operator < (const city_name_t& other) const{
		return memcmp(str,other.str,sizeof(str)) < 0;
	}
	bool operator > (const city_name_t& other) const{
		return memcmp(str,other.str,sizeof(str)) > 0;
	}
	bool operator == (const city_name_t& other) const{
		return memcmp(str,other.str,sizeof(str)) == 0;
	}
};

std::map<city_name_t,int> mapping;
std::vector<city_name_t> rmapping;
std::vector<int> happiness;
std::vector<std::vector<std::pair<int,int> > > g;

const int INF = 1e6;
std::vector<int> vis;
std::vector<int> dis;
std::vector<std::vector<int> > pre;

void dijkstra(const int &begin){
	typedef std::pair<int,int> pii;
	std::priority_queue<pii,std::vector<pii>,std::greater<pii> > queue;
	std::fill(dis.begin(),dis.end(),INF);
	std::fill(vis.begin(),vis.end(),0);
	queue.push(std::make_pair(0,begin));
	while(!queue.empty()){
		pii pi = queue.top();
		queue.pop();
		if(vis[pi.second]){
			continue;
		}
		vis[pi.second] = 1;
		std::vector<std::pair<int,int> > &gg = g[pi.second];
		for(int i=0;i<gg.size();i++){
			int &to = gg[i].first;
            if(!vis[to]){
                int &cost = gg[i].second;
                int tmp = cost+pi.first;
                if(tmp<dis[to]){
                    dis[to] = tmp;
                    pre[to].clear();
                    queue.push(std::make_pair(tmp,to));
                }
                if(tmp<=dis[to]){
                    pre[to].push_back(pi.second);
                }
            }

		}
	}
}

void dfs(const int &begin,const int &deep,const int &happiness_val,
		std::vector<int> &rode,int &max_happiness_val,int &max_happiness_val_avg,std::vector<int> &best_rode,int &rode_num){
	vis[begin] = 1;
	rode.push_back(begin);
	std::vector<int> &pre1 = pre[begin];
	if(pre1.empty()){
		int happiness_val_avg = happiness_val/deep;
		if(happiness_val > max_happiness_val){
			max_happiness_val = happiness_val;
			max_happiness_val_avg = happiness_val_avg;
			best_rode = rode;
		}else if (happiness_val == max_happiness_val){
			if(happiness_val_avg > max_happiness_val){
				max_happiness_val = happiness_val_avg;
				best_rode = rode;
			}
		}
		rode_num++;
	}else{
		for(std::vector<int>::iterator it=pre1.begin();it!=pre1.end();it++){
			const int &i = *it;
			if(!vis[i]){
				dfs(i,deep+1,happiness_val+happiness[i],rode,max_happiness_val,max_happiness_val_avg,best_rode,rode_num);
			}
		}
	}

	rode.pop_back();
	vis[begin] = 0;
}


int main(){
	std::ios::sync_with_stdio(false);
	int n,k;
	std::cin >> n >> k;
	int city1,city2;
	std::string str;
	int t;
	std::cin >> str;
	rmapping.resize(n);
	happiness.resize(n);
	g.resize(n);
	mapping.insert(std::make_pair(str,0));
	rmapping[0] = str;
	happiness[0] = 0;
	for(int i=1;i<n;i++){
		std::cin >> str >> t;
		mapping.insert(std::make_pair(str,i));
		rmapping[i] = str;
		happiness[i] = t;
	}
	for(int i=0;i<k;i++){
		std::cin >> str;
		city1 = mapping[str];
		std::cin >> str >> t;
		city2 = mapping[str];
		g[city1].push_back(std::make_pair(city2,t));
		g[city2].push_back(std::make_pair(city1,t));
	}
	int dist_city = mapping["ROM"];
	int begin_city = 0;
	vis.resize(n);
	pre.resize(n);
	dis.resize(n);
	dijkstra(begin_city);
	std::vector<int> rode,best_rode;
	std::fill(vis.begin(),vis.end(),0);
	int max_happiness_val=0;
	int max_happiness_val_avg=0;
	int rode_num=0;
	dfs(dist_city,0,happiness[dist_city],rode,max_happiness_val,max_happiness_val_avg,best_rode,rode_num);
	std::cout << rode_num << ' ' << dis[dist_city] << ' ' << max_happiness_val << ' ' << max_happiness_val_avg << std::endl;
    for(std::vector<int>::reverse_iterator it=best_rode.rbegin();it!=best_rode.rend();it++){
        if(it!=best_rode.rbegin()){
            std::cout << "->";
        }
        std::cout << rmapping[*it].str;
    }
    std::cout.flush();
}
/*
1087 All Roads Lead to Rome （30 分）
Indeed there are many different tourist routes from our city to Rome. You are supposed to find your clients the route with the least cost while gaining the most happiness.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (2≤N≤200), the number of cities, and K, the total number of routes between pairs of cities; followed by the name of the starting city. The next N?1 lines each gives the name of a city and an integer that represents the happiness one can gain from that city, except the starting city. Then K lines follow, each describes a route between two cities in the format City1 City2 Cost. Here the name of a city is a string of 3 capital English letters, and the destination is always ROM which represents Rome.

Output Specification:
For each test case, we are supposed to find the route with the least cost. If such a route is not unique, the one with the maximum happiness will be recommanded. If such a route is still not unique, then we output the one with the maximum average happiness -- it is guaranteed by the judge that such a solution exists and is unique.

Hence in the first line of output, you must print 4 numbers: the number of different routes with the least cost, the cost, the happiness, and the average happiness (take the integer part only) of the recommanded route. Then in the next line, you are supposed to print the route in the format City1->City2->...->ROM.

Sample Input:
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
Sample Output:
3 3 195 97
HZH->PRS->ROM
作者: CHEN, Yue
单位: 浙江大学
时间限制: 200 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
