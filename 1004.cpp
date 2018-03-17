#include<vector>
#include<map>
#include<cstdio>

typedef std::vector<int> node_t;
typedef std::map<int,node_t> map_t;
typedef std::map<int,int> r_map_t;

map_t map;
r_map_t r_map;
int n,m;

void dfs(int key,int depth){
//	printf("key=%d,depth=%d\n",key,depth);
	int &num = r_map[depth];
	node_t &node = map[key];
	if(node.empty()){
		num++;
	}else{
		for(node_t::iterator it=node.begin();it!=node.end();it++){
			dfs(*it,depth+1);
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
//	printf("n=%d,m=%d\n",n,m);
	int t1,t2,t3;
	for(int i=0;i<m;i++){
		scanf("%d%d",&t1,&t2);
//		printf("t1=%d,t2=%d\n",t1,t2);
		for(int j=0;j<t2;j++){
			scanf("%d",&t3);
//			printf("t3=%d\n",t3);
			map[t1].push_back(t3);
		}
	}
	dfs(1,0);
	for(r_map_t::iterator it=r_map.begin();it!=r_map.end();it++){
		if(it!= r_map.begin()){
			printf(" ");
		}
		printf("%d",it->second);
	}
	printf("\n");
}
/*
1004. Counting Leaves (30)
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
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input

Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
Output

For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.

Sample Input
2 1
01 1 02
Sample Output
0 1

*/ 
