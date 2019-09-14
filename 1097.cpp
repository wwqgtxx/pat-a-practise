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
#include<map>
std::pair<int,int> memory[100000];
bool has[10005];

int main(){
	memset(has,0,sizeof(has));
	int first_node;
	int n;
	scanf("%d%d",&first_node,&n);
	int address,key,next;
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&address,&key,&next);
		memory[address].first = key;
		memory[address].second = next;
	}
	std::vector<std::pair<int,int> > vec1,vec2;
	int now=first_node;
	while(now!=-1){
		std::pair<int,int> pair;
		pair.first = now;
		pair.second = memory[now].first;
		int val = abs(pair.second);
		if(!has[val]){
			has[val] = true;
			vec1.push_back(pair);
		}else{
			vec2.push_back(pair);
		}
		now = memory[now].second;
	}
	for(int i=0;i<vec1.size();i++){
		if(i!=0){
			printf(" %05d\n",vec1[i].first);	
		}
		printf("%05d %d",vec1[i].first,vec1[i].second);
		if(i==vec1.size()-1){
			printf(" -1\n");
		}
	}
	
	for(int i=0;i<vec2.size();i++){
		if(i!=0){
			printf(" %05d\n",vec2[i].first);	
		}
		printf("%05d %d",vec2[i].first,vec2[i].second);
		if(i==vec2.size()-1){
			printf(" -1\n");
		}
	}
} 

/*
1097 Deduplication on a Linked List （25 分）
Given a singly linked list L with integer keys, you are supposed to remove the nodes with duplicated absolute values of the keys. That is, for each value K, only the first node of which the value or absolute value of its key equals K will be kept. At the mean time, all the removed nodes must be kept in a separate list. For example, given L being 21→-15→-15→-7→15, you must output 21→-15→-7, and the removed list -15→15.

Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, and a positive N (≤10
?5
?? ) which is the total number of nodes. The address of a node is a 5-digit nonnegative integer, and NULL is represented by ?1.

Then N lines follow, each describes a node in the format:

Address Key Next
where Address is the position of the node, Key is an integer of which absolute value is no more than 10
?4
?? , and Next is the position of the next node.

Output Specification:
For each case, output the resulting linked list first, then the removed list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
Sample Output:
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1
作者: CHEN, Yue
单位: 浙江大学
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
