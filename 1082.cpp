#include<cstdio>
#include<stdint.h>
#include<algorithm>
#include<set>
#include<iostream> 
#include<vector>
std::string map[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main(){
	std::ios::sync_with_stdio(false);
	std::string str;
	std::cin >> str;
	std::vector<std::string> vec;
	vec.push_back("");
	if(str[0]=='-'){
		vec.push_back("Fu");
		str.erase(str.begin());
	}
	if(str.length()==9){
		vec.push_back(map[str[0]-'0']);
		vec.push_back("Yi");
		str.erase(str.begin());
	}
	for(int i=1;i>=0;i--){
		if(str.length()==i*4+4){
			vec.push_back(map[str[0]-'0']);
			if(str[0]!='0'){
				vec.push_back("Qian");
			}
			str.erase(str.begin());
		}
		if(str.length()==i*4+3){
			if(str[0]=='0'){
				if(vec.back()!=map[0]){
					vec.push_back(map[0]);
				}
			}else{
				vec.push_back(map[str[0]-'0']);
				vec.push_back("Bai");
			}
			str.erase(str.begin());
		}
		if(str.length()==i*4+2){
			if(str[0]=='0'){
				if(vec.back()!=map[0]){
					vec.push_back(map[0]);
				}
			}else{
				vec.push_back(map[str[0]-'0']);
				vec.push_back("Shi");
			}
			str.erase(str.begin());
		}
		if(str.length()==i*4+1){
			if(str[0]=='0'){
				if(vec.back()!=map[0]){
					vec.push_back(map[0]);
				}
			}else{
				vec.push_back(map[str[0]-'0']);
			}
			if(vec.back()==map[0]){
				vec.pop_back();
			}
			if(i==1){
				vec.push_back("Wan");
			}
			str.erase(str.begin());
		}
	}

	vec.erase(vec.begin());
	if(vec.empty()){
		vec.push_back(map[0]);
	}
	for(std::vector<std::string>::iterator it=vec.begin();it!=vec.end();it++){
		if(it!=vec.begin()){
			std::cout << ' ';
		}
		std::cout << *it;
	}
	std::cout << std::endl;
} 

/*
1082 Read Number in Chinese （25 分）
Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way. Output Fu first if it is negative. For example, -123456789 is read as Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu. Note: zero (ling) must be handled correctly according to the Chinese tradition. For example, 100800 is yi Shi Wan ling ba Bai.

Input Specification:
Each input file contains one test case, which gives an integer with no more than 9 digits.

Output Specification:
For each test case, print in a line the Chinese way of reading the number. The characters are separated by a space and there must be no extra space at the end of the line.

Sample Input 1:
-123456789
Sample Output 1:
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
Sample Input 2:
100800
Sample Output 2:
yi Shi Wan ling ba Bai
作者: CHEN, Yue
单位: 浙江大学
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
