#include<cstdio>
#include<stdint.h>
#include<algorithm>
#include<set>
#include<iostream>
#include<vector>
#include<sstream>

const int INF = INT32_MAX;

struct Node {
    int id;
    Node *left;
    Node *right;

    Node() : id(INF), left(nullptr), right(nullptr) {}

    Node(const Node &node) = default;

    Node &operator=(const Node &node) = default;

};

Node nodes[100];
std::vector<int> vector;
std::vector<std::vector<int>> result;

void dfs(Node *node,const int &deep=0){
    if(node->left!=nullptr){
        dfs(node->left,deep+1);
    }
    node->id = vector.back();
    vector.pop_back();
    if(result.size()<deep+1){
        result.resize(deep+1);
    }
    result[deep].push_back(node->id);
    if(node->right!= nullptr){
        dfs(node->right,deep+1);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        std::cin >> a >> b;
        auto &node = nodes[i];
        if (a != -1) {
            node.left = nodes + a;
        }
        if (b != -1) {
            node.right = nodes + b;
        }
    }
    vector.resize(n);
    for (auto &item:vector) {
        std::cin >> item;
    }
    std::sort(vector.begin(),vector.end(),std::greater<int>());
    dfs(nodes);
    std::stringstream ss;
    for(auto &item1:result){
        for(auto &item2:item1){
            ss << item2 << ' ';
        }
    }
    std::string str = ss.str();
    str.pop_back();
    std::cout << str;
    std::cout.flush();
}
/*
1099 Build A Binary Search Tree （30 分）
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST. You are supposed to output the level order traversal sequence of that tree. The sample is illustrated by Figure 1 and 2.

figBST.jpg

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤100) which is the total number of nodes in the tree. The next N lines each contains the left and the right children of a node in the format left_index right_index, provided that the nodes are numbered from 0 to N?1, and 0 is always the root. If one child is missing, then ?1 will represent the NULL child pointer. Finally N distinct integer keys are given in the last line.

Output Specification:
For each test case, print in one line the level order traversal sequence of that tree. All the numbers must be separated by a space, with no extra space at the end of the line.

Sample Input:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
Sample Output:
58 25 82 11 38 67 45 73 42
作者: CHEN, Yue
单位: 浙江大学
时间限制: 200 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
