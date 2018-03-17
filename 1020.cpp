#include<vector>
#include<iostream>
#include<memory>
#include<queue>

struct Node{
	int id;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;
	
	Node(const int &id):id(id){
//		std::cout << "new:"<< id << std::endl;
	}
	
//	~Node(){
//		std::cout << "delete:" << id << std::endl;
//	}
};

template<class _t0,class _t1,class _t2>
void build(_t0 &node_ptr,_t1 post_begin,_t1 post_end,_t2 in_begin,_t2 in_end){
//	std::cout << "build {";
//	for(auto _it=post_begin;_it!=post_end;_it++){
//		std::cout << *_it << ' ';
//	}
//	std::cout << "},{";
//	for(auto _it=in_begin;_it!=in_end;_it++){
//		std::cout << *_it << ' ';
//	}
//	std::cout << '}' << std::endl;
	int id = *(post_end-1);
	node_ptr = std::make_shared<Node>(id);
	int i=0;
	auto it=in_begin;
	while(it!=in_end){
		if(*it == node_ptr->id){
			break;
		}
		it++;
		i++;
	}
	bool no_left=false;
	bool no_right=false;
	if(it == in_begin){
		no_left = true;
	}
	if(it+1 == in_end){
		no_right = true;
	}
	if(!no_left){
//		std::cout << "left" << std::endl;
		build(node_ptr->left,post_begin,post_begin+i,in_begin,it);
	}
	if(!no_right){
//		std::cout << "right" << std::endl;
		build(node_ptr->right,post_begin+i,post_end-1,it+1,in_end);
	}
}

void level_output(std::shared_ptr<Node> node_ptr){
	std::vector<int> vec;
	std::queue<std::shared_ptr<Node>> queue;
	queue.emplace(node_ptr);
	while(!queue.empty()){
		auto ptr = queue.front();
		queue.pop();
		vec.emplace_back(ptr->id);
		if(ptr->left != nullptr){
			queue.emplace(ptr->left);
		}
		if(ptr->right != nullptr){
			queue.emplace(ptr->right);
		}
	}
	for(auto it=vec.begin();it!=vec.end();it++){
		if(it!=vec.begin()){
			std::cout << ' ';
		}
		std::cout << *it;
	}
	std::cout << std::endl;
}

int main(){
	int n;
	std::cin >> n;
	std::vector<int> post(n);
	std::vector<int> in(n);
	for(int i=0;i<n;i++){
		std::cin >> post[i];
	}
	for(int i=0;i<n;i++){
		std::cin >> in[i];
	}
	std::shared_ptr<Node> root;
	build(root,post.begin(),post.end(),in.begin(),in.end());
	level_output(root);
	return 0;
} 

/*
1020. Tree Traversals (25)
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
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2
*/
