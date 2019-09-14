#include<cstdio>
#include<cmath>
#include<cstring>
#include<stdint.h>
#include<algorithm>
#include<set>
#include<iostream>
#include<iomanip>
#include<vector>
#include<stack>
std::vector<std::vector<int> > g;
int n,m;

std::vector<int> result;

void dfs(const int& id,const int& deep){
	std::vector<int> &vec = g[id];
	result[deep+1] += vec.size();
	for(int i=0;i<vec.size();i++){
		dfs(vec[i],deep+1);
	}
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
    	int id,k;
    	std::cin >> id >> k;
    	std::vector<int> &vec = g[id];
    	vec.resize(k);
    	for(int j=0;j<k;j++){
    		std::cin >> vec[j];
		}
	}
	result.resize(n+1);
	result[0] = 0;
	result[1] = 1;
	dfs(1,1);
	int max=result[0];
	int max_num=0;
	for(int i=1;i<result.size();i++){
		if(result[i]>max){
			max = result[i];
			max_num = i;
		}
	}
	std::cout << max << ' ' << max_num << std::endl;
} 
/*
1094 The Largest Generation （25 分）
A family hierarchy is usually presented by a pedigree tree where all the nodes on the same level belong to the same generation. Your task is to find the generation with the largest population.

Input Specification:
Each input file contains one test case. Each case starts with two positive integers N (<100) which is the total number of family members in the tree (and hence assume that all the members are numbered from 01 to N), and M (<N) which is the number of family members who have children. Then M lines follow, each contains the information of a family member in the following format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a family member, K (>0) is the number of his/her children, followed by a sequence of two-digit ID's of his/her children. For the sake of simplicity, let us fix the root ID to be 01. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the largest population number and the level of the corresponding generation. It is assumed that such a generation is unique, and the root level is defined to be 1.

Sample Input:
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
Sample Output:
9 4
作者: CHEN, Yue
单位: 浙江大学
时间限制: 200 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
