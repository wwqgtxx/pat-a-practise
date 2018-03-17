#include<iostream>
#include<iomanip>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<cstdint>

int main(){
	int n,k;
	std::cin >> n >> k;
	std::vector<int> window_lines(k,0);
	std::set<std::pair<int,int>> customers;
	std::string str;
	int t;
	for(int i=0;i<n;i++){
		std::cin >> str >> t;
		if(t>60){
			t=60;
		}
		int hh = (str[0]-'0')*10+(str[1]-'0');
		int mm = (str[3]-'0')*10+(str[4]-'0');
		int ss = (str[6]-'0')*10+(str[7]-'0');
		int s = hh*60*60 + mm*60 + ss;
		if(s > 17*60*60){
			continue;
		}
//		std::cout << s << std::endl;
		customers.emplace(s,t*60);
	}
	
//	int hh=8;
//	int mm=0;
//	int ss=0;
	int s=8*60*60;
	double wait_time = 0;
	int num=0;
	while(!customers.empty()){
//		std::cout << "now time is " << hh << ':' << mm << ':' << ss << std::endl;
		for(auto &i : window_lines){
			if(i>0){
//				std::cout << i << std::endl;
				i--;
			}
		}
		auto c_it = customers.begin();
		while( c_it!=customers.end() && s >= c_it->first ){
			bool all_full=true;
			for(auto &i : window_lines){
				if(i == 0){
					all_full=false;
					i = c_it->second;
					wait_time += double(s - c_it->first)/60;
					num++;
//					std::cout << "now time is " << hh << ':' << mm << ':' << ss << std::endl;
//					std::cout << "erase:" << c_it->first << std::endl;
//					std::cout << "he wait:" << s - c_it->first << 's' << std::endl;
//					std::cout << "----------------"<< std::endl;
					customers.erase(c_it);
					break;
				}
			}
			if(all_full){
				break;
			}
			c_it = customers.begin();
		}
		
		
		
		s++;
//		ss++;
//		if(ss==60){
//			mm++;
//			ss=0;
//			if(mm==60){
//				hh++;
//				mm=0;
//			}
//		}
	}
	
	wait_time /= num;
//	std::cout << "num=" << num << std::endl;
	
	std::cout << std::fixed << std::setprecision(1) << wait_time << std::endl;
} 

/*
1017. Queueing at Bank (25)
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
Suppose a bank has K windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available. It is assumed that no window can be occupied by a single customer for more than 1 hour.

Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the customers.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=10000) - the total number of customers, and K (<=100) - the number of windows. Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing time in minutes of a customer. Here HH is in the range [00, 23], MM and SS are both in [00, 59]. It is assumed that no two customers arrives at the same time.

Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.

Output Specification:

For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.

Sample Input:
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
Sample Output:
8.2

*/ 
