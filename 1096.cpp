#include<cstdio>
#include<cmath>
#include<cstring>
#include<stdint.h>
#include<algorithm>
#include<set>
#include<iostream>
#include<iomanip>
#include<vector>
#include<stack>
#include<map>

int main() {
    std::ios::sync_with_stdio(false);
    int64_t num;
    std::cin >> num;
    int64_t num_sqrt = static_cast<int64_t>(sqrt(num));
    int64_t max_count = 0;
    int64_t first = num;
    for (int64_t i = 2; i <= num_sqrt; i++) {
        int64_t count = 0;
        int64_t start = i;
        int64_t tmp = num;
        while (tmp % start == 0) {
            tmp = tmp / start;
            count++;
            start++;
        }
        if (count > max_count) {
            max_count = count;
            first = i;
        }
    }
    if (max_count == 0) {
        std::cout << '1' << std::endl << num;
    } else {
        std::cout << max_count << std::endl << first;
        for (int i = 1; i < max_count; i++) {
            std::cout << '*' << first + i;
        }
    }
    std::cout.flush();
}
/*
1096 Consecutive Factors （20 分）
Among all the factors of a positive integer N, there may exist several consecutive numbers. For example, 630 can be factored as 3×5×6×7, where 5, 6, and 7 are the three consecutive numbers. Now given any positive N, you are supposed to find the maximum number of consecutive factors, and list the smallest sequence of the consecutive factors.

Input Specification:
Each input file contains one test case, which gives the integer N (1<N<2
?31
?? ).

Output Specification:
For each test case, print in the first line the maximum number of consecutive factors. Then in the second line, print the smallest sequence of the consecutive factors in the format factor[1]*factor[2]*...*factor[k], where the factors are listed in increasing order, and 1 is NOT included.

Sample Input:
630
Sample Output:
3
5*6*7
作者: CHEN, Yue
单位: 浙江大学
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
