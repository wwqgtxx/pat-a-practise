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

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<int> vec(n+1);
	std::vector<int> dis(n+1);
	int sum=0;
	for(int i=1;i<=n;i++){
		std::cin >> vec[i];
		dis[i] = sum;
		sum += vec[i];
	}
	int m;
	std::cin >> m;
	std::vector<int> result(m);
	std::stringstream ss;
	int from,to;
	for(int i=0;i<m;i++){
		std::cin >> from >> to;
		if(from > to){
			std::swap(from,to);
		}
		int d = dis[to]-dis[from];
		ss << std::min(d,sum-d) << std::endl;
	}
	std::cout << ss.str();
}
