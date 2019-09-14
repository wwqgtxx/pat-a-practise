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

const int64_t MAX = 1000000007L;

int main(){
    std::ios::sync_with_stdio(false);
    std::string str;
    std::cin >> str;
    const size_t length = str.length();
    std::vector<int64_t> count_p(length),count_t(length);
    int64_t count=0;
    for(int i=0;i<length;i++){
        if(str[i]=='P'){
            count++;
        }
        count_p[i] = count;
    }
    count = 0;
    for(int i=length-1;i>=0;i--){
        if(str[i]=='T'){
            count++;
        }
        count_t[i] = count;
    }
    count = 0;
    for(int i=1;i<length-1;i++){
        if(str[i]=='A'){
            int64_t tmp = ((count_p[i-1]*count_t[i+1])%MAX+count)%MAX;
            count = tmp;
        }
    }
    std::cout << count << std::endl;
}
/*
1093 Count PAT's （25 分）
The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, the 4th, and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.

Now given any string, you are supposed to tell the number of PAT's contained in the string.

Input Specification:
Each input file contains one test case. For each case, there is only one line giving a string of no more than 10
?5
??  characters containing only P, A, or T.

Output Specification:
For each test case, print in one line the number of PAT's contained in the string. Since the result may be a huge number, you only have to output the result moded by 1000000007.

Sample Input:
APPAPT
Sample Output:
2
作者: CAO, Peng
单位: Google
时间限制: 150 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
