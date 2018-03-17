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

int main(){
	std::string str1,str2,str3,str4;
	std::cin >> str1 >> str2 >> str3 >> str4;
	bool is_first = true;
	char first;
	int second;
	int size = std::min(str1.size(),str2.size());
	for(int i=0;i<size;i++){
		if(str1[i] == str2[i]){
			if(is_first){
				first = str1[i]; 
				if(first >= 'A' && first <= 'G'){
//					std::cout << "first=" << first << std::endl;
					is_first = false;
				}
			}else{
				second = str1[i];
				if(second >= '0' && second <= '9'){
//					std::cout << "second=" << second << std::endl;
					second = second - '0';
					break;
				}
				if(second >= 'A' && second <= 'N'){
//					std::cout << "second=" << second << std::endl;
					second = second - 'A' + 10;
					break;
				}
			}
		}
	}
	size = std::min(str3.size(),str4.size());
	int third;
	for(int i=0;i<size;i++){
		if(str3[i] == str4[i]){ 
			if( (str3[i] >= 'A' && str3[i] <= 'Z') || (str3[i] >= 'a' && str3[i] <= 'z')){
				third = i;
				break; 
			}
		}
	}
	switch(first){
		case 'A':{
			std::cout << "MON ";
			break;
		}
		case 'B':{
			std::cout << "TUE ";
			break;
		}
		case 'C':{
			std::cout << "WED ";
			break;
		}
		case 'D':{
			std::cout << "THU ";
			break;
		}
		case 'E':{
			std::cout << "FRI ";
			break;
		}
		case 'F':{
			std::cout << "SAT ";
			break;
		}
		case 'G':{
			std::cout << "SUN ";
			break;
		}
	}
	std::cout << std::setfill('0') << std::setw(2) << second
			  << ':'
			  << std::setfill('0') << std::setw(2) << third
			  << std::endl;
	return 0;
}

/*
1061. Dating (20)
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
Sherlock Holmes received a note with some strange strings: "Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm". It took him only a minute to figure out that those strange strings are actually referring to the coded time "Thursday 14:04" -- since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter 'D', representing the 4th day in a week; the second common character is the 5th capital letter 'E', representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from A to N, respectively); and the English letter shared by the last two strings is 's' at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.

Input Specification:

Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.

Output Specification:

For each test case, print the decoded time in one line, in the format "DAY HH:MM", where "DAY" is a 3-character abbreviation for the days in a week -- that is, "MON" for Monday, "TUE" for Tuesday, "WED" for Wednesday, "THU" for Thursday, "FRI" for Friday, "SAT" for Saturday, and "SUN" for Sunday. It is guaranteed that the result is unique for each case.

Sample Input:
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
Sample Output:
THU 14:04

*/
