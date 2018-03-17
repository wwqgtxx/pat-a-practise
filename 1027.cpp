#include<iostream>
#include<iomanip>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<cstdint>
#include<cmath>
#include<deque>
#include<queue>
#include<list>

inline char get_c(const int &t){
	if(t<10){
		return t+'0';
	}else{
		return t - 10 + 'A';
	}
}

int main(){
	int a,b,c;
	std::cin >> a >> b >> c;
	std::string str("#000000");
	int t;
	
	t = a%13;
	a /= 13;
	
	str[1] = get_c(a);
	str[2] = get_c(t);
	
	t = b%13;
	b /= 13;
	
	str[3] = get_c(b);
	str[4] = get_c(t);
	
	t = c%13;
	c /= 13;
	
	str[5] = get_c(c);
	str[6] = get_c(t);
	std::cout << str << std::endl;
	return 0;
}

/*
1027. Colors in Mars (20)
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
People in Mars represent the colors in their computers in a similar way as the Earth people. That is, a color is represented by a 6-digit number, where the first 2 digits are for Red, the middle 2 digits for Green, and the last 2 digits for Blue. The only difference is that they use radix 13 (0-9 and A-C) instead of 16. Now given a color in three decimal numbers (each between 0 and 168), you are supposed to output their Mars RGB values.

Input

Each input file contains one test case which occupies a line containing the three decimal color values.

Output

For each test case you should output the Mars RGB value in the following format: first output "#", then followed by a 6-digit number where all the English characters must be upper-cased. If a single color is only 1-digit long, you must print a "0" to the left.

Sample Input
15 43 71
Sample Output
#123456

*/
