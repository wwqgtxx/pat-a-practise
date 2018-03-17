#include<map>
#include<iostream>
#include<iomanip>
#include<cmath>

const double EPS = 1e-7;

int main(){
	typedef std::map<int,double,std::greater<int> > map_t;
	map_t map;
	int num;
	int tmp1;
	double tmp2;
	int tmp3;
	double tmp4;
	std::cin >> num;
	for(int i=0;i<num;i++){
		std::cin >> tmp1 >> tmp2;
		map[tmp1] = tmp2;
	}
	std::cin >> num;
	map_t new_map;
	for(int i=0;i<num;i++){
		std::cin >> tmp1 >> tmp2;
		for(auto it=map.begin();it!=map.end();it++){
			tmp3 = it->first + tmp1;
			tmp4 = new_map[tmp3] + it->second * tmp2;
			new_map[tmp3] = tmp4;
			if(fabs(tmp4-0) < EPS){
				new_map.erase(tmp3);
			}	
		}
	}
	map = new_map;
	std::cout << map.size();
	for(map_t::iterator it = map.begin();it!= map.end();it++){
		std::cout << std::fixed << std::setprecision(1);
        std::cout << " " << it->first << " " << it->second;
	}
	std::cout << std::endl;
	
	return 0;
} 

/*
1009. Product of Polynomials (25)
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
This time, you are supposed to find A*B where A and B are two polynomials.

Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.

Output Specification:

For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6
*/