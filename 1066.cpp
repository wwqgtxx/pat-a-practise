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

struct Node{
	int id;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;
	
	Node():id(0xffffffff){}
	Node(const int &id):id(id){}
	
	void right_rotate(){
//        88
//    70
//61      75
		std::swap(this->id,this->left->id);
//        70
//    88
//61      75
		std::swap(this->left,this->right);
//        70
//            88
//        61      75
		std::swap(this->left,this->right->left);
//        70
//    61      88
//                75
		std::swap(this->right->right,this->right->left);
//        70
//    61      88
//        75
	}
	
	void left_rotate(){
		std::swap(this->id,this->right->id);
		std::swap(this->right,this->left);
		std::swap(this->right,this->left->right);
		std::swap(this->left->right,this->left->left);
	}
	
	void insert(const int &id){
//		std::cout << "node=" << this->id << " insert:" << id << std::endl;
		if(this->id == 0xffffffff){
			this->id = id;
			return;
		}
		if(id < this->id){
			if(this->left == nullptr){
				this->left = std::make_shared<Node>(id);
			}else{
				this->left->insert(id);
				if(this->is_balance()){
//					std::cout << "not_balance!" << std::endl;
					if(id < this->left->id){
						this->right_rotate();
					}else{
						this->left->left_rotate();
						this->right_rotate();
					}
				}
			}
		}else{
			if(this->right == nullptr){
				this->right = std::make_shared<Node>(id);
			}else{
				this->right->insert(id);
				
				if(this->is_balance()){
//					std::cout << "not_balance!" << std::endl;
					if(id > this->right->id){
						this->left_rotate();
					}else{
						this->right->right_rotate();
						this->left_rotate();
					}
					
				}
			}
		}
	}
	
	bool is_balance(){
		int l=0,r=0;
		if(this->left != nullptr){
			l = this->left->deep();
		}
		if(this->right != nullptr){
			r = this->right->deep();
		}
//		std::cout << "node=" << id << " l=" << l << ",r=" << r << std::endl;
		return abs(l-r) >= 2;
	}
	
	int deep(){
		int l=0,r=0;
		if(this->left != nullptr){
			l += this->left->deep();
		}
		if(this->right != nullptr){
			r += this->right->deep();
		}
		return std::max(l,r)+1;
	}
};

int main(){
	int n;
	std::cin >> n;
	Node root;
	int t;
	for(int i=0;i<n;i++){
		std::cin >> t;
		root.insert(t);
	}
	std::cout << root.id << std::endl;
}

/*
1066. Root of AVL Tree (25)
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
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.

    
    
Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=20) which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print ythe root of the resulting AVL tree in one line.

Sample Input 1:
5
88 70 61 96 120
Sample Output 1:
70
Sample Input 2:
7
88 70 61 96 120 90 65
Sample Output 2:
88
*/
