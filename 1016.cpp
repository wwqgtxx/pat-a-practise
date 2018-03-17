#include<map>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<set>

int time_costs[25] = {0};
int day_time_cost = 0;

int get_amount(int dd,int hh,int mm){
	int amount=0;
	for(int i=0;i<dd;i++){
		amount += day_time_cost*60;
	}
	for(int i=0;i<hh;i++){
		amount += time_costs[i]*60;
	}
	amount += time_costs[hh]*mm;
	return amount;
}

int main(){
	for(int i=0;i<24;i++){
		std::cin >> time_costs[i];
		day_time_cost += time_costs[i];
	}
	int n;
	std::cin >> n;
	std::map<std::string,std::set<std::pair<std::string,std::string>>> map;
	std::string str1,str2,str3;
	for(int i=0;i<n;i++){
		std::cin >> str1 >> str2 >> str3;
		auto &set = map[str1];
		set.emplace(str2.substr(3),str3);
	}
	std::stringstream ss;
	std::string month(str2.begin(),str2.begin()+2);
	
	for(auto it=map.begin();it!=map.end();it++){
		auto &set = it->second;
		ss.str("");
		ss.clear();
		ss << it->first << ' ' << month << std::endl;
		std::string line1("on-line");
		std::string line2("off-line");
		auto it1=set.begin();
		auto it2=set.begin();
		it2++;
		double total=0;
		while(it1!=set.end()&&it2!=set.end()){
			if(it1->second == line1 && it2->second == line2){
				auto &str1 = it1->first;
				auto &str2 = it2->first;
				int dd1 = (str1[0]-'0')*10+(str1[1]-'0');
				int hh1 = (str1[3]-'0')*10+(str1[4]-'0');
				int mm1 = (str1[6]-'0')*10+(str1[7]-'0');
				int dd2 = (str2[0]-'0')*10+(str2[1]-'0');
				int hh2 = (str2[3]-'0')*10+(str2[4]-'0');
				int mm2 = (str2[6]-'0')*10+(str2[7]-'0');
				int time = (dd2-dd1)*24*60+(hh2-hh1)*60+(mm2-mm1);
//				double amount = get_amount(dd2,hh2,mm2)-get_amount(dd1,hh1,mm1);
				int time2 = 0;
				double amount = 0;
				
				while(dd1!=dd2){
					time2 += 24*60;
					amount += day_time_cost*60;
					dd1++;
				}
				if(hh2==hh1){
					time2 += mm2-mm1;
					amount += time_costs[hh1]*(mm2-mm1);
				}else{
					time2 += mm2;
					amount += time_costs[hh2]*mm2;
					if(hh2<hh1){
						time2 -= 24*60;
						amount -= day_time_cost*60;
						hh2--;
						while(hh2>=0){
							time2 +=60;
							amount += time_costs[hh2]*60;
							hh2--;
						}
					}
					time2 += 60-mm1;
					amount += time_costs[hh1]*(60-mm1);
					hh1++;
					while(hh1!=hh2&&hh1<24){
						time2 += 60;
						amount += time_costs[hh1]*60;
						hh1++;
					}
				}
				if (time2!=time){
					std::cerr << "time=" << time << ",time2=" << time2 <<std::endl;
					throw std::bad_exception(); 
					return -1;
				}
				amount /= 100;
				total += amount;
				ss << it1->first << ' ' 
//						  << it1->second << '|'
						  << it2->first << ' ' 
//						  << it2->second
						  << time << ' '
						  << '$' << std::fixed << std::setprecision(2) << amount
						  << std::endl;
			}
			it1++;
			it2++;
		}
		ss << "Total amount: $" << std::fixed << std::setprecision(2) << total << std::endl;
		
		if(total>0){
			std::cout << ss.str();
		}
		
	}
	return 0;
}

/*
1016. Phone Bills (25)
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
A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

Input Specification:

Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.

The next line contains a positive number N (<= 1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".

For each test case, all dates will be within a single month. Each "on-line" record is paired with the chronologically next record for the same customer provided it is an "off-line" record. Any "on-line" records that are not paired with an "off-line" record are ignored, as are "off-line" records not paired with an "on-line" record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

Output Specification:

For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
*/
