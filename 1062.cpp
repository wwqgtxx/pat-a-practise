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

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n,l,h;
	std::cin >> n >> l >> h;
	std::string id;
	int virtue,talent;
	typedef std::tuple<int,int,int,std::string> _t;
	std::vector<_t> sages,noblemen,foolmen,other;
	for(int i=0;i<n;i++){
		std::cin >> id >> virtue >> talent;
		if(virtue >= l && talent >= l){
			if(virtue >= h && talent >= h){
				sages.emplace_back(-(virtue+talent),-virtue,-talent,id);
			}else if(virtue >= h && talent < h){
				noblemen.emplace_back(-(virtue+talent),-virtue,-talent,id);
			}else if(virtue < h && talent < h && virtue >= talent){
				foolmen.emplace_back(-(virtue+talent),-virtue,-talent,id);
			}else{
				other.emplace_back(-(virtue+talent),-virtue,-talent,id);
			}
		}
	}
	std::sort(sages.begin(),sages.end());
	std::sort(noblemen.begin(),noblemen.end());
	std::sort(foolmen.begin(),foolmen.end());
	std::sort(other.begin(),other.end());
	std::stringstream ss;
	ss << sages.size()+noblemen.size()+foolmen.size()+other.size() << std::endl;
	for(auto &item : sages){
		std::tie(std::ignore,virtue,talent,id) = item;
		ss << id << ' ' << -virtue << ' ' << -talent << std::endl;
	}
//	ss << "-----------------" << std::endl;
	for(auto &item : noblemen){
		std::tie(std::ignore,virtue,talent,id) = item;
		ss << id << ' ' << -virtue << ' ' << -talent << std::endl;
	}
//	ss << "-----------------" << std::endl;
	for(auto &item : foolmen){
		std::tie(std::ignore,virtue,talent,id) = item;
		ss << id << ' ' << -virtue << ' ' << -talent << std::endl;
	}
//	ss << "-----------------" << std::endl;
	for(auto &item : other){
		std::tie(std::ignore,virtue,talent,id) = item;
		ss << id << ' ' << -virtue << ' ' << -talent << std::endl;
	}
	std::cout << ss.str();
}

/*
1062. Talent and Virtue (25)
ʱ������
200 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Li
About 900 years ago, a Chinese philosopher Sima Guang wrote a history book in which he talked about people's talent and virtue. According to his theory, a man being outstanding in both talent and virtue must be a "sage��ʥ�ˣ�"; being less excellent but with one's virtue outweighs talent can be called a "nobleman�����ӣ�"; being good in neither is a "fool man�����ˣ�"; yet a fool man is better than a "small man��С�ˣ�" who prefers talent than virtue.

Now given the grades of talent and virtue of a group of people, you are supposed to rank them according to Sima Guang's theory.

Input Specification:

Each input file contains one test case. Each case first gives 3 positive integers in a line: N (<=105), the total number of people to be ranked; L (>=60), the lower bound of the qualified grades -- that is, only the ones whose grades of talent and virtue are both not below this line will be ranked; and H (<100), the higher line of qualification -- that is, those with both grades not below this line are considered as the "sages", and will be ranked in non-increasing order according to their total grades. Those with talent grades below H but virtue grades not are cosidered as the "noblemen", and are also ranked in non-increasing order according to their total grades, but they are listed after the "sages". Those with both grades below H, but with virtue not lower than talent are considered as the "fool men". They are ranked in the same way but after the "noblemen". The rest of people whose grades both pass the L line are ranked after the "fool men".

Then N lines follow, each gives the information of a person in the format:

ID_Number Virtue_Grade Talent_Grade
where ID_Number is an 8-digit number, and both grades are integers in [0, 100]. All the numbers are separated by a space.
Output Specification:

The first line of output must give M (<=N), the total number of people that are actually ranked. Then M lines follow, each gives the information of a person in the same format as the input, according to the ranking rules. If there is a tie of the total grade, they must be ranked with respect to their virtue grades in non-increasing order. If there is still a tie, then output in increasing order of their ID's.

Sample Input:
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
Sample Output:
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/