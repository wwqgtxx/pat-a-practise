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

std::vector<std::vector<int>> g;
std::vector<int> vis;

void dfs(const int &begin,const int &deep,int &count){
//	std::cout << "get:" << begin << std::endl;
	if(deep > vis[begin]){//剪枝：如果你在第一层的时候已经过了某节点，那么在第三层的时候你就不需要再去遍历该节点了。因为底层的遍历情况永远比高层丰富。
//		std::cout << "ok" << std::endl;
		if(!vis[begin]){
			++count;
		}
		vis[begin] = deep;
		if(deep > 1){//剪枝：当深度不能满足的时候直接跳过遍历 
			for(auto &item:g[begin]){
				dfs(item,deep-1,count);
			}
		}	
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n,l;
	std::cin >> n >> l;
	g.resize(n+1);
	vis.resize(n+1);
	int m,mm;
	for(int i=1;i<=n;i++){
		std::cin >> m;
		for(int j=0;j<m;j++){
			std::cin >> mm;
			g[mm].emplace_back(i);
		}
	}
	std::cin >> m;
	int count;
	for(int i=0;i<m;i++){
		std::cin >> mm;
		std::fill(vis.begin(),vis.end(),0);
		count = 0;
		dfs(mm,l+1,count);
		--count;
		std::cout << count << std::endl;
	}
	return 0;
}

/*
1076. Forwards on Weibo (30)
时间限制
3000 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=1000), the number of users; and L (<=6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to N. Then N lines follow, each in the format:

M[i] user_list[i]

where M[i] (<=100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that are followed by user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.

Then finally a positive K is given, followed by K UserID's for query.

Output Specification:

For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can triger, assuming that everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.

Sample Input:
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:
4
5

*/
