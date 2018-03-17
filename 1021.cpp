#include<vector> 
#include<iostream>
#include<map>
#include<algorithm>
#include<set>

std::vector<std::vector<int>> g;
std::vector<int> father;
std::vector<char> vis;

int find(int a){
	int b = a;
	while(b!=father[b]){
		b = father[b];
	} 
	
	int c = a;
	while(c!=b){//路径压缩 
		a = father[c];
		father[c] = b;
		c = a;
	}
	
	return b; 
}

bool join(const int &a,const int &b){
	int aa = find(a);
	int bb = find(b);
	
	if(aa != bb){
		father[aa] = bb;
		return true;
	}else{
		return false;
	}
} 

void dfs(const int &a,int deep,int &max_deep,std::set<int> &max_points){
//	if(vis[a]){
//		return;
//	}
	vis[a] = true;
	auto &gg = g[a];
	for(auto &b:gg){
		if(!vis[b]){
			dfs(b,deep+1,max_deep,max_points);
		}
	}
	if(deep>max_deep){
		max_deep = deep;
		max_points.clear();
		max_points.emplace(a);
	}else if(deep==max_deep){
		max_points.emplace(a);
	}
//	vis[a] = false;
}

int main(){
	int n;
	std::cin >> n;
	g.resize(n+1);
	vis.resize(n+1,0);
	father.reserve(n+1);
	for(int i=0;i<=n;i++){
		father.emplace_back(i);
	}
	int a,b;
	int components = n;
	for(int i=1;i<n;i++){
		std::cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		if(join(a,b)){
			components--;
		}
	}
//	int components=0;
//	for(int i=1;i<=n;i++){
//		if(father[i]==i){
//			components++;
//		}
//	}
	if(components != 1){
		std::cout << "Error: " << components << " components" << std::endl;
	}else{
		std::fill(vis.begin(),vis.end(),0);
		int max_deep=0;
		std::set<int> max_points,max_points2;
		
		dfs(1,0,max_deep,max_points);
		
		int first_max;
//		for(auto it=max_points.begin();it!=max_points.end();it++){
//			std::cout << *it << std::endl;
//		}
//		std::cout << "--------------" << std::endl;

		std::fill(vis.begin(),vis.end(),0);
		first_max = *max_points.begin();
		max_deep = 0;
		dfs(first_max,0,max_deep,max_points2);
		max_points2.insert(max_points.begin(),max_points.end());
		
		for(auto &i : max_points2){
			std::cout << i << std::endl;
		}
	}
	return 0;
		
}

/*
1021. Deepest Root (25)
时间限制
1500 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N-1 lines follow, each describes an edge by given the two adjacent nodes' numbers.

Output Specification:

For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print "Error: K components" where K is the number of connected components in the graph.

Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components
*/ 
