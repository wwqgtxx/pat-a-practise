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

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::deque<int> cps,pvs;
	int nc,np;
	std::cin >> nc;
	cps.resize(nc);
	for(int i=0;i<nc;i++){
		std::cin >> cps[i];
	}
	std::cin >> np;
	pvs.resize(np);
	for(int i=0;i<np;i++){
		std::cin >> pvs[i];
	}
	std::sort(cps.begin(),cps.end(),std::greater<int>());
	std::sort(pvs.begin(),pvs.end(),std::greater<int>());
	int sum = 0;
	{
		auto it1 = cps.begin();
		auto it2 = pvs.begin();
		while( (!cps.empty()) && (!pvs.empty()) && ((*it1) > 0) && ((*it2) > 0) ){
			//std::cout << *it1 << ' ' << *it2 << std::endl;
			sum += (*it1) * (*it2);
			cps.pop_front();
			pvs.pop_front();
			it1 = cps.begin();
			it2 = pvs.begin();
		}		
	}
	{
		auto it1 = cps.rbegin();
		auto it2 = pvs.rbegin();
		while( (!cps.empty()) && (!pvs.empty()) && ((*it1) < 0) && ((*it2) < 0) ){
			//std::cout << *it1 << ' ' << *it2 << std::endl;
			sum += (*it1) * (*it2);
			cps.pop_back();
			pvs.pop_back();
			it1 = cps.rbegin();
			it2 = pvs.rbegin();
		}		
	}

	std::cout << sum << std::endl;
}
/*
1037. Magic Coupon (25)
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
The magic shop in Mars is offering some magic coupons. Each coupon has an integer N printed on it, meaning that when you use this coupon with a product, you may get N times the value of that product back! What is more, the shop also offers some bonus product for free. However, if you apply a coupon with a positive N to this bonus product, you will have to pay the shop N times the value of the bonus product... but hey, magically, they have some coupons with negative N's!

For example, given a set of coupons {1 2 4 -1}, and a set of product values {7 6 -2 -3} (in Mars dollars M$) where a negative value corresponds to a bonus product. You can apply coupon 3 (with N being 4) to product 1 (with value M$7) to get M$28 back; coupon 2 to product 2 to get M$12 back; and coupon 4 to product 4 to get M$3 back. On the other hand, if you apply coupon 3 to product 4, you will have to pay M$12 to the shop.

Each coupon and each product may be selected at most once. Your task is to get as much money back as possible.

Input Specification:

Each input file contains one test case. For each case, the first line contains the number of coupons NC, followed by a line with NC coupon integers. Then the next line contains the number of products NP, followed by a line with NP product values. Here 1<= NC, NP <= 105, and it is guaranteed that all the numbers will not exceed 230.

Output Specification:

For each test case, simply print in a line the maximum amount of money you can get back.

Sample Input:
4
1 2 4 -1
4
7 6 -2 -3
Sample Output:
43

*/
