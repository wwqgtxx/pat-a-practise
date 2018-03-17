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

struct Node{
	int id = -1;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;
	
	Node(const int& id):id(id){}
	Node() = default;
	Node(const Node& node){
		id = node.id;
		if(node.left != nullptr){
			left = std::make_shared<Node>(*(node.left));
		}
		if(node.right != nullptr){
			right = std::make_shared<Node>(*(node.right));
		}
		
	}
	
//	~Node(){
//		std::cout << "delete:" << id << std::endl;
//	}
	
	void insert(const int& id){
		if(this->id == -1){
			this->id = id;
		}else{
			if(id >= this->id){
				if(right == nullptr){
					right = std::make_shared<Node>(id);
				}else{
					right->insert(id);
				}
			}else{
				if(left == nullptr){
					left = std::make_shared<Node>(id);
				}else{
					left->insert(id);
				}
			}
		}
	}
	
	void mirror(){
		std::swap(left,right);
		if(left != nullptr){
			left->mirror();
		}
		if(right != nullptr){
			right->mirror();
		}
	}
	
	void preorder(std::vector<int> &vec){
		vec.emplace_back(id);
		if(left != nullptr){
			left->preorder(vec);
		}
		if(right != nullptr){
			right->preorder(vec);
		}
	}
	
	void preorder(){
		std::vector<int> vec;
		preorder(vec);
		for(auto it = vec.begin();it!=vec.end();it++){
			if(it != vec.begin()){
				std::cout << ' ';
			}
			std::cout << *it;
		}
		std::cout << std::endl;
	}
	
	void postorder(std::vector<int> &vec){
		if(left != nullptr){
			left->postorder(vec);
		}
		if(right != nullptr){
			right->postorder(vec);
		}
		vec.emplace_back(id);
	}
	
	void postorder(){
		std::vector<int> vec;
		postorder(vec);
		for(auto it = vec.begin();it!=vec.end();it++){
			if(it != vec.begin()){
				std::cout << ' ';
			}
			std::cout << *it;
		}
		std::cout << std::endl;
	}
};

int main(){
	Node root;
	int n;
	std::cin >> n;
	std::vector<int> vec(n);
	for(int i=0;i<n;i++){
		std::cin >> vec[i];
		root.insert(vec[i]);
	}
	
	Node root2(root);
	root2.mirror();
	
	std::vector<int> vec1,vec2;
	root.preorder(vec1);
	root2.preorder(vec2);
	
	if(vec1 == vec){
		std::cout << "YES" << std::endl;
		root.postorder();
	}else if(vec2 == vec){
		std::cout << "YES" << std::endl;
		root2.postorder();
	}else{
		std::cout << "NO" << std::endl;
	}
	
	return 0;
} 

/*
1043. Is It a Binary Search Tree (25)
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
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.

Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of a BST.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in a line "YES" if the sequence is the preorder traversal sequence of a BST or the mirror image of a BST, or "NO" if not. Then if the answer is "YES", print in the next line the postorder traversal sequence of that tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:
7
8 6 5 7 10 8 11
Sample Output 1:
YES
5 7 6 8 11 10 8
Sample Input 2:
7
8 10 11 8 6 7 5
Sample Output 2:
YES
11 8 10 7 5 6 8
Sample Input 3:
7
8 6 8 5 10 9 11
Sample Output 3:
NO
*/
