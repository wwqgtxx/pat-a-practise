#include<cstdio>
#include<cstring>
#include<stdint.h>
#include<algorithm>
#include<set>
#include<iostream> 
#include<vector>
#include<map>

int main(){
	std::ios::sync_with_stdio(false);
	bool was[128];
	memset(was,0,sizeof(was));
	std::string str1,str2;
	std::cin >> str1 >> str2;
	for(int i=0;i<str1.size();i++){
		str1[i] = toupper(str1[i]);
		str2[i] = toupper(str2[i]);
		if(str1[i]!=str2[i]){
			if(!was[str1[i]]){
				was[str1[i]] = true;
				printf("%c",str1[i]);
			}
			str2.insert(str2.begin()+i,str1[i]);
		}
	}
} 

/*
1084 Broken Keyboard （20 分）
On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.

Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.

Input Specification:
Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or _ (representing the space). It is guaranteed that both strings are non-empty.

Output Specification:
For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.

Sample Input:
7_This_is_a_test
_hs_s_a_es
Sample Output:
7TI
作者: CHEN, Yue
单位: 浙江大学
时间限制: 200 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
