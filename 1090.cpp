#include<cstdio>
#include<cmath>
#include<stdint.h>
#include<algorithm>
#include<set>
#include<iostream>
#include<iomanip>
#include<vector>

int n;
double p,r;
std::vector<std::pair<int,int> > s_vec;

int max_deep=0;
int max_deep_count=0;

void build_tree(const int &which,const int &deep){
    if(deep>max_deep){
        max_deep = deep;
        max_deep_count=0;
    }
    if(deep==max_deep){
        max_deep_count++;
    }
    std::vector<std::pair<int,int> >::iterator
            begin = std::lower_bound(s_vec.begin(),s_vec.end(),std::make_pair(which,0)),
            end = std::upper_bound(s_vec.begin(),s_vec.end(),std::make_pair(which,n));
    for(;begin!=end;begin++){
        build_tree(begin->second,deep+1);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin >> n >> p >> r;
    int t;
    s_vec.resize(n);
    for(int i=0;i<n;i++){
        std::cin >> s_vec[i].first;
    	s_vec[i].second = i;
    }
	std::sort(s_vec.begin(),s_vec.end());
    build_tree(s_vec.begin()->second,0);
    double price = p * pow(1+r/100,max_deep);
    std::cout << std::fixed << std::setprecision(2) << price << ' ' << max_deep_count << std::endl;
}
/*
1090 Highest Price in Supply Chain （25 分）
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the highest price we can expect from some retailers.

Input Specification:
Each input file contains one test case. For each case, The first line contains three positive numbers: N (≤10
?5
?? ), the total number of the members in the supply chain (and hence they are numbered from 0 to N?1); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then the next line contains N numbers, each number S
?i
??  is the index of the supplier for the i-th member. S
?root
??  for the root supplier is defined to be ?1. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the highest price we can expect from some retailers, accurate up to 2 decimal places, and the number of retailers that sell at the highest price. There must be one space between the two numbers. It is guaranteed that the price will not exceed 10
?10
?? .

Sample Input:
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
Sample Output:
1.85 2
作者: CHEN, Yue
单位: 浙江大学
时间限制: 200 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
