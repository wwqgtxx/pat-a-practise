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

typedef std::vector<int> vec_t;
typedef std::vector<int>::iterator it_t;

bool dfs(const it_t &begin,
		const it_t &end,
		vec_t &result,
		int m){
	const int &v = *begin;
	m -= v;
	if(m > 0){
		for(auto it=begin+1;it<end;it++){
			if((*it) > m){
				break;
			}
			if(dfs(it,end,result,m)){
				result.emplace_back(v);
				return true;
			}
		}
	}else if(m == 0){
		result.emplace_back(v);
		return true;
	}
	
	return false;
}

int main(){
	int n,m;
	std::cin >> n >> m;
	std::vector<int> vec;
	vec.reserve(n+1);
	int t;
	vec.emplace_back(0);
	int sum=0;
	for(int i=0;i<n;i++){
		std::cin >> t;
		if(t <= m){
			vec.emplace_back(t);
			sum += t;
		}
	}
	if(sum < m){//for test 6
		std::cout << "No Solution";
	}else{
		std::sort(vec.begin(),vec.end());
		std::vector<int> result;
		auto begin = vec.begin();
		auto end = vec.end();
		if(dfs(begin,end,result,m)){
			for(auto it=result.rbegin()+1;it!=result.rend();it++){
				if(it!=result.rbegin()+1){
					std::cout << ' ';
				}
				std::cout << *it;
			}
		}else{
			std::cout << "No Solution";
		}
	}
	
	
	std::cout << std::endl;
} 

/*
1068. Find More Coins (30)
时间限制
150 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she must pay the exact amount. Since she has as many as 104 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find some coins to pay for it.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (<=104, the total number of coins) and M(<=102, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the face values V1 <= V2 <= ... <= Vk such that V1 + V2 + ... + Vk = M. All the numbers must be separated by a space, and there must be no extra space at the end of the line. If such a solution is not unique, output the smallest sequence. If there is no solution, output "No Solution" instead.

Note: sequence {A[1], A[2], ...} is said to be "smaller" than sequence {B[1], B[2], ...} if there exists k >= 1 such that A[i]=B[i] for all i < k, and A[k] < B[k].

Sample Input 1:
8 9
5 9 8 7 2 3 4 1
Sample Output 1:
1 3 5
Sample Input 2:
4 8
7 2 4 3
Sample Output 2:
No Solution
*/

/*
如果使用动态规划：
d[i][j]=true表示前i个硬币能够选出若干个达到价值j。
关键等式为d[i][j]=d[i-1][j]||d[i-1][j-coin[i]]，分别为不用coin[i]和用coin[i]两种方案。
迭代过程中用used[i][j]=ture表示在d[i][j]==true时存在可以用coin[i]的方案。
由于结果要求优先选小面值硬币，先将硬币从大到小排序，从大面值硬币开始处理，迭代到最后的小面值。越小的硬币越晚参与处理，能参与到更多方案中。
从小面值开始，根据used数组进行回溯可得出结果。提交代码后AC。

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;  
bool COINcmp(int a, int b)
{
  return a > b;
}
int main()
{
  int n, m; 
  cin >> n >> m;
  vector<int>coins(n+1);
  vector<int>dp(m + 1,0);
  vector<vector<bool>>choice(n + 1) ;
  vector<int>ans;
  for (int i = 1; i <= n; i++)
  {
    cin >> coins[i]; 
    choice[i].resize(m + 1);
  }
    sort(coins.begin() + 1, coins.begin()+ n + 1,COINcmp);
    for (int i = 1; i <= n; i++)//dp递归方程
    { //这里的钱币已经从大到小排好序了，题目要最小的先用，所以越后面满足的coins[i]会覆盖前面的
      for (int value = m; value >= coins[i]; value--)
      {//对于钱coins[i]，根据题意要没有找零，所以coins[i]只能用在价值在value=m~coins[i]
        if (dp[value] <= dp[value - coins[i]] + coins[i])
        {
          dp[value] = dp[value - coins[i]] + coins[i];
          choice[i][value] = true;
        }
        else
          choice[i][value] = false;
      }
    } 
    if (dp[m] != m)  cout << "No Solution" << endl;
    else
    { 
      while (n > 0)
      {
        if (choice[n][m])
        {
          ans.push_back(coins[n]);
          m-= coins[n]; 
        } 
        n--;
      }  
      n = 0;
      cout << ans[n++];
      while (n < ans.size())
        cout << " " << ans[n++];
        cout << endl;
    } 
    system("pause");
  return 0;
}
*/
