#include<cstdio>
#include<cstring>
#include<stdint.h>
#include<algorithm>
#include<set>
#include<iostream> 
#include<vector>
#include<stack>
#include<map>

std::vector<int> pre_order; 
std::vector<int> in_order; 
std::stack<int> stack;

void post(int in_left,int in_right,int pre_root){
	if(in_left>in_right)return;
	int &root = pre_order[pre_root];
	int in_pos = std::find(in_order.begin(),in_order.end(),root)-in_order.begin();
	post(in_left,in_pos-1,pre_root+1);//left
	post(in_pos+1,in_right,pre_root+in_pos-in_left+1);//right
	std::cout << root;
	if(pre_root == 0){
		std::cout << std::endl;
	}else{
		std::cout << ' ';
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	
	std::string str;
	int x;
	for(int i=0;i<2*n;i++){
		std::cin >> str;
		if(str[1]=='u'){//push
			std::cin >> x;
			pre_order.push_back(x);
			stack.push(x);
		}else{//pop
			in_order.push_back(stack.top());
			stack.pop();
		}
	}
	post(0,n-1,0);
	return 0;
}
/*
1086 Tree Traversals Again （25 分）
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.


Figure 1
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:
For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1
作者: CHEN, Yue
单位: 浙江大学
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
