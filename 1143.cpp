#include<cstdio>
#include<bits/stdc++.h>

struct Node{
	int id;
//	Node* father;
//	int deep;
	Node* left;
	Node* right;
	
	Node():left(nullptr),right(nullptr){}
	Node(const int &id):id(id),left(nullptr),right(nullptr){}
	
//	~Node(){
//		std::cout << id << std::endl;
//	}
	
	void insert(const int &t){
//		std::cout << "insert:" << t << std::endl;
		if(t<id){
			if(left == nullptr){
				left = new Node(t);
//				left->father = this;
//				left->deep = deep+1;
			}else{
				left->insert(t);
			}
		}else{
			if(right == nullptr){
				right = new Node(t);
//				right->father = this;
//				right->deep = deep+1;
			}else{
				right->insert(t);
			}
		}
	}
	
	Node* find(const int &t){
		if(t == id){
			return this;
		}
		if(t<id){
			if(left == nullptr){
				return nullptr;
			}else{
				return left->find(t);
			}
		}else{
			if(right == nullptr){
				return nullptr;
			}else{
				return right->find(t);
			}
		}
	}
	
	Node* findf(const int &t1,const int &t2,Node *&n1,Node *&n2){
		if(t1 == id){
			n1 = this;
			n2 = find(t2);
			return this;
		}
		if(t2 == id){
			n2 = this;
			n1 = find(t1);
			return this;
		}
		if(t1 < id && t2 < id){
			if(left == nullptr){
				return nullptr;
			}else{
				return left->findf(t1,t2,n1,n2);
			}
		}
		if(t1 > id && t2 > id){
			if(right == nullptr){
				return nullptr;
			}else{
				return right->findf(t1,t2,n1,n2);
			}
		}
		n1 = find(t1);
		n2 = find(t2);
		return this;
		
	}
};

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int m,n;
	std::cin >> m >> n;
	
	int t,tt;
	std::cin >> t;
	Node root(t);
//	root.deep = 1;
	for(int i=1;i<n;i++){
		std::cin >> t;
		root.insert(t);
	}
	std::stringstream ss;
	for(int i=0;i<m;i++){
		std::cin >> t >> tt;
//		Node *n1 = root.find(t);
//		Node *n2 = root.find(tt);
		Node *n1 = nullptr,*n2 = nullptr,*n = nullptr;
		n = root.findf(t,tt,n1,n2);
		if(n1 == nullptr && n2 == nullptr){
			ss << "ERROR: " << t << " and " << tt << " are not found." << std::endl;
		}else if(n1 == nullptr){
			ss << "ERROR: " << t << " is not found." << std::endl;
		}else if(n2 == nullptr){
			ss << "ERROR: " << tt << " is not found." << std::endl;
		}else{
//			if(n1->deep > n2->deep){
//				std::swap(n1,n2);
//			}
//			Node *n = nullptr;
//			int deep = n1->deep;
//			while(n2->deep > deep){
//				n2 = n2->father;
//			}
//			while(n1!=nullptr){
//				if(n1==n2){
//					n = n1;
//					break;
//				}
//				n1 = n1->father;
//				n2 = n2->father;
//			}

			int ttt = n->id;
			if(ttt!=t && ttt!=tt){
				ss << "LCA of " << t << " and " << tt << " is " << ttt << '.' << std::endl;
			}else if(ttt == t){
				ss << t << " is an ancestor of " << tt << '.' << std::endl;
			}else{
				ss << tt << " is an ancestor of " << t << '.' << std::endl;
			}
			
//			ss << "find:" << t << ' ' << tt << ' ' << n->id << std::endl;
		}
	}
	std::cout << ss.str();
}

/*
7-4 Lowest Common Ancestor£¨30 ·Ö£©
The lowest common ancestor (LCA) of two nodes U and V in a tree is the deepest node that has both U and V as descendants.

A binary search tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
Given any two nodes in a BST, you are supposed to find their LCA.

Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers: M (¡Ü 1,000), the number of pairs of nodes to be tested; and N (¡Ü 10,000), the number of keys in the BST, respectively. In the second line, N distinct integers are given as the preorder traversal sequence of the BST. Then M lines follow, each contains a pair of integer keys U and V. All the keys are in the range of int.

Output Specification:

For each given pair of U and V, print in a line LCA of U and V is A. if the LCA is found and A is the key. But if A is one of U and V, print X is an ancestor of Y. where X is A and Y is the other node. If U or V is not found in the BST, print in a line ERROR: U is not found. or ERROR: V is not found. or ERROR: U and V are not found..

Sample Input:

6 8
6 3 1 2 5 4 8 7
2 5
8 7
1 9
12 -3
0 8
99 99
Sample Output:

LCA of 2 and 5 is 3.
8 is an ancestor of 7.
ERROR: 9 is not found.
ERROR: 12 and -3 are not found.
ERROR: 0 is not found.
ERROR: 99 and 99 are not found.
*/
