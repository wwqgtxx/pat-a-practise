#include<iostream>
#include<iomanip>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<cstdint>
#include<cmath>
#include<deque>
#include<queue>
#include<list>

int main(){
	int n;
	std::cin >> n;
//	std::vector<int> window_lines(k,0);
	std::set<std::pair<int,int>> customers,vip_customers;
	std::string str;
	int t;
	int is_vip; 
	for(int i=0;i<n;i++){
		std::cin >> str >> t >> is_vip;
		t = std::min(t,120);
		int hh = (str[0]-'0')*10+(str[1]-'0');
		int mm = (str[3]-'0')*10+(str[4]-'0');
		int ss = (str[6]-'0')*10+(str[7]-'0');
		int s = hh*60*60 + mm*60 + ss;
		if(s > 21*60*60){
			continue;
		}
		if(is_vip){
			vip_customers.emplace(s,t*60);
		}
		customers.emplace(s,t*60);
		
	}
	int k,m;
	std::cin >> k >> m;
	std::vector<int> tables_use(k+1,0);
	std::set<int> tables,vip_tables;
	
	std::vector<char> vipt(k+1,0);
	for(int i=0;i<m;i++){
		std::cin >> t;
		vipt[t] = true;
		vip_tables.emplace(t);
	}
	for(int i=1;i<=k;i++){
		tables.emplace(i);
	}
	
	std::list<std::pair<int,int>> working_list;
	std::map<int,int> result_map;
	
	int hh=8;
	int mm=0;
	int ss=0;
	int s=8*60*60;
	double wait_time = 0;
	int num=0;
	while(s < 21*60*60){
//		std::cout << "now time is " << hh << ':' << mm << ':' << ss << std::endl;
		auto wl_it = working_list.begin();
		while(wl_it!=working_list.end()){
			auto &time = wl_it->second;
			auto &table = wl_it->first;
			time--;
			if(time == 0){
//				tables_use[table]++;
				if(vipt[table]){
					vip_tables.emplace(table);
				}
				tables.emplace(table);
				wl_it = working_list.erase(wl_it);
			}else{
				wl_it++;
			}
		}
		
		if(!vip_tables.empty()){
			auto vc_it = vip_customers.begin();
			while( !vip_tables.empty() && !vip_customers.empty() && s >= vc_it->first ){
				t = *vip_tables.begin();
//				std::cout << "get vip table:" << t << std::endl;
				tables.erase(t);
				vip_tables.erase(t);
				
				working_list.emplace_back(t,vc_it->second);
				result_map.emplace(s,vc_it->first);
				tables_use[t]++;
				
				
				customers.erase(*vc_it);
				vip_customers.erase(vc_it);
				vc_it = vip_customers.begin();
			}
		}
		
		auto c_it = customers.begin();
		while( !tables.empty() && !customers.empty() && s >= c_it->first ){
			t = *tables.begin();
//			std::cout << "get table:" << t << std::endl;
			tables.erase(t);
			vip_tables.erase(t);
			
			working_list.emplace_back(t,c_it->second);
			result_map.emplace(s,c_it->first);
			tables_use[t]++;
			
			
			customers.erase(c_it);
			vip_customers.erase(*c_it);
			c_it = customers.begin();
		}
		
		
		
		s++;
		ss++;
		if(ss==60){
			mm++;
			ss=0;
			if(mm==60){
				hh++;
				mm=0;
			}
		}
	}
	
	for(auto &p : result_map){
		int t1 = p.second;
		int ss1 = t1%60;
		t1 /= 60;
		int mm1 = t1%60;
		t1 /= 60;
		int hh1 = t1;
		
		int t2 = p.first;
		int ss2 = t2%60;
		t2 /= 60;
		int mm2 = t2%60;
		t2 /= 60;
		int hh2 = t2;
		
		std::cout << std::setfill('0')
		 		  << std::setw(2) << hh1 << ':' 
				  << std::setw(2) << mm1 << ':' 
				  << std::setw(2) << ss1 << ' '
		          << std::setw(2) << hh2 << ':' 
				  << std::setw(2) << mm2 << ':' 
				  << std::setw(2) << ss2 << ' '
		          << round(double(p.first - p.second)/60) << std::endl;
		
	}
	for(int i=1;i<k+1;i++){
		if(i != 1){
			std::cout << ' ';
		}
		std::cout << tables_use[i];
	}
	std::cout << std::endl;
} 

/*
1026. Table Tennis (30)
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
A table tennis club has N tables available to the public. The tables are numbered from 1 to N. For any pair of players, if there are some tables open when they arrive, they will be assigned to the available table with the smallest number. If all the tables are occupied, they will have to wait in a queue. It is assumed that every pair of players can play for at most 2 hours.

Your job is to count for everyone in queue their waiting time, and for each table the number of players it has served for the day.

One thing that makes this procedure a bit complicated is that the club reserves some tables for their VIP members. When a VIP table is open, the first VIP pair in the queue will have the priviledge to take it. However, if there is no VIP in the queue, the next pair of players can take it. On the other hand, if when it is the turn of a VIP pair, yet no VIP table is available, they can be assigned as any ordinary players.

Input Specification:

Each input file contains one test case. For each case, the first line contains an integer N (<=10000) - the total number of pairs of players. Then N lines follow, each contains 2 times and a VIP tag: HH:MM:SS - the arriving time, P - the playing time in minutes of a pair of players, and tag - which is 1 if they hold a VIP card, or 0 if not. It is guaranteed that the arriving time is between 08:00:00 and 21:00:00 while the club is open. It is assumed that no two customers arrives at the same time. Following the players' info, there are 2 positive integers: K (<=100) - the number of tables, and M (< K) - the number of VIP tables. The last line contains M table numbers.

Output Specification:

For each test case, first print the arriving time, serving time and the waiting time for each pair of players in the format shown by the sample. Then print in a line the number of players served by each table. Notice that the output must be listed in chronological order of the serving time. The waiting time must be rounded up to an integer minute(s). If one cannot get a table before the closing time, their information must NOT be printed.

Sample Input:
9
20:52:00 10 0
08:00:00 20 0
08:02:00 30 0
20:51:00 10 0
08:10:00 5 0
08:12:00 10 1
20:50:00 10 0
08:01:30 15 1
20:53:00 10 1
3 1
2
Sample Output:
08:00:00 08:00:00 0
08:01:30 08:01:30 0
08:02:00 08:02:00 0
08:12:00 08:16:30 5
08:10:00 08:20:00 10
20:50:00 20:50:00 0
20:51:00 20:51:00 0
20:52:00 20:52:00 0
3 3 2

*/

