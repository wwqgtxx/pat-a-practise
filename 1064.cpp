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

void level(const int &i,
	       const std::vector<int>::iterator &begin,
		   const std::vector<int>::iterator &end,
		   std::vector<int>::iterator &it,
		   std::vector<int> &result){
	if(begin+i > end){
		return;
	}
	level(i*2,begin,end,it,result);
	result[i-1] = *(it++);
	level(i*2+1,begin,end,it,result);
}

int main(){
	int n;
	std::cin >> n;
	std::vector<int> vec(n);
	for(int i=0;i<n;i++){
		std::cin >> vec[i];
	}
	std::sort(vec.begin(),vec.end());
	std::vector<int> result(n);
	auto it = vec.begin();
	level(1,vec.begin(),vec.end(),it,result);
	std::stringstream ss;
	for(int i=0;i<n;i++){
		ss << result[i] << ' ';
	}
	std::string str(ss.str());
	str.pop_back();
	std::cout << str << std::endl;
	return 0;
} 

/*
1064. Complete Binary Search Tree (30)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.

Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input:
10
1 2 3 4 5 6 7 8 9 0
Sample Output:
6 3 8 1 5 7 9 0 2 4
*/
