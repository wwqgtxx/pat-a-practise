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
	int begin,value,to;
	std::map<int,std::pair<int,int>> map;
	int first,n,k;
	std::cin >> first >> n >> k;
	for(int i=0;i<n;i++){
		std::cin >> begin >> value >> to;
		map.emplace(begin,std::make_pair(value,to));
	}
	std::vector<std::pair<int,int>> vec;
	begin = first;
	while(begin != -1){
		std::tie(value,to) = map[begin];
		vec.emplace_back(begin,value);
		begin = to;
	}
	for(auto it=vec.begin();it+k <= vec.end();it+=k){
		std::reverse(it,it+k);
	}
	bool is_first = true;
	for(auto &item : vec){
		if(is_first){
			is_first = false;
		}else{
			std::cout << std::setfill('0') << std::setw(5) << item.first
					  << std::endl;	
		} 
		std::cout << std::setfill('0') << std::setw(5) << item.first 
				  << ' ' 
				  << item.second
				  << ' ';
	}
	std::cout << -1 << std::endl;
} 

/*
1074. Reversing Linked List (25)
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
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K = 3, then you must output 3→2→1→6→5→4; if K = 4, you must output 4→3→2→1→5→6.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 105) which is the total number of nodes, and a positive K (<=N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/
