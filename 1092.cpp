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

int arr1[128];

int main(){
    std::ios::sync_with_stdio(false);
    memset(arr1,0,sizeof(arr1));
    std::string str1,str2;
    std::cin >> str1 >> str2;
    for(int i=0;i<str1.size();i++){
    	arr1[str1[i]]++;
	}
	int more=0;
	int need=0;
	for(int i=0;i<str2.size();i++){
		arr1[str2[i]]--;
		if(arr1[str2[i]]<0){
			need++;
		}
	}
	if(need>0){
		std::cout << "No " << need << std::endl; 
	}else{
		for(int i=0;i<128;i++){
	    	more += arr1[i];
		}
		std::cout << "Yes " << more << std::endl;
	}
} 

/*
1092 To Buy or Not to Buy （20 分）
Eva would like to make a string of beads with her favorite colors so she went to a small shop to buy some beads. There were many colorful strings of beads. However the owner of the shop would only sell the strings in whole pieces. Hence Eva must check whether a string in the shop contains all the beads she needs. She now comes to you for help: if the answer is Yes, please tell her the number of extra beads she has to buy; or if the answer is No, please tell her the number of beads missing from the string.

For the sake of simplicity, let's use the characters in the ranges [0-9], [a-z], and [A-Z] to represent the colors. For example, the 3rd string in Figure 1 is the one that Eva would like to make. Then the 1st string is okay since it contains all the necessary beads with 8 extra ones; yet the 2nd one is not since there is no black bead and one less red bead.

figbuy.jpg

Figure 1

Input Specification:
Each input file contains one test case. Each case gives in two lines the strings of no more than 1000 beads which belong to the shop owner and Eva, respectively.

Output Specification:
For each test case, print your answer in one line. If the answer is Yes, then also output the number of extra beads Eva has to buy; or if the answer is No, then also output the number of beads missing from the string. There must be exactly 1 space between the answer and the number.

Sample Input 1:
ppRYYGrrYBR2258
YrR8RrY
Sample Output 1:
Yes 8
Sample Input 2:
ppRYYGrrYB225
YrR8RrY
Sample Output 2:
No 2
作者: CHEN, Yue
单位: 浙江大学
时间限制: 150 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
