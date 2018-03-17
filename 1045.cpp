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
	int N;
	std::cin >> N;
	int n,m;
	std::cin >> n;
	std::vector<int> order(n+1);
	for(int i=1;i<=n;i++){
		std::cin >> order[i];
	}
	std::cin >> m;
	std::vector<int> colors(m+1);
	for(int i=1;i<=m;i++){
		std::cin >> colors[i];
	}
	std::vector<std::vector<int>> dp(2,std::vector<int>(m+1,0));
	bool which = false;
	for(int i=1;i<=n;i++){
		which = !which;
		for(int j=1;j<=m;j++){
			if(order[i] == colors[j]){
				dp[which][j] = std::max(dp[!which][j],dp[which][j-1])+1;
			}else{
				dp[which][j] = std::max(dp[!which][j],dp[which][j-1]);
			}
		}
	}
	std::cout << dp[which][m] << std::endl;
	/*
	std::vector<std::vector<int>> dp(n+1,std::vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(order[i] == colors[j]){
				dp[i][j] = std::max(dp[i-1][j],dp[i][j-1])+1;
			}else{
				dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]);
			}	
		}
	}
	*/
	/*LCS:
	std::vector<std::vector<int>> dp(n+1,std::vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){			 
			if(order[i] == colors[j]){
				dp[i][j] = dp[i-1][j-1]+1;
			}else{
				dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]);
			}	
		}
	}
	*/
//	std::cout << dp[n][m] << std::endl;
} 

/*
1045. Favorite Color Stripe (30)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Eva is trying to make her own color stripe out of a given one. She would like to keep only her favorite colors in her favorite order by cutting off those unwanted pieces and sewing the remaining parts together to form her favorite color stripe.

It is said that a normal human eye can distinguish about less than 200 different colors, so Eva's favorite colors are limited. However the original stripe could be very long, and Eva would like to have the remaining favorite stripe with the maximum length. So she needs your help to find her the best result.

Note that the solution might not be unique, but you only have to tell her the maximum length. For example, given a stripe of colors {2 2 4 1 5 5 6 3 1 1 5 6}. If Eva's favorite colors are given in her favorite order as {2 3 1 5 6}, then she has 4 possible best solutions {2 2 1 1 1 5 6}, {2 2 1 5 5 5 6}, {2 2 1 5 5 6 6}, and {2 2 3 1 1 5 6}.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=200) which is the total number of colors involved (and hence the colors are numbered from 1 to N). Then the next line starts with a positive integer M (<=200) followed by M Eva's favorite color numbers given in her favorite order. Finally the third line starts with a positive integer L (<=10000) which is the length of the given stripe, followed by L colors on the stripe. All the numbers in a line are separated by a space.

Output Specification:

For each test case, simply print in a line the maximum length of Eva's favorite stripe.

Sample Input:
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
Sample Output:
7
*/
