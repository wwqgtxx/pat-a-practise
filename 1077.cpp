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
	std::vector<std::string> vec;
	std::string str;
	int n;
	std::cin >> n;
	std::getline(std::cin,str);
	vec.resize(n);
	for(int i=0;i<n;i++){
		std::getline(std::cin,vec[i]);
	}
	str.clear();
	int size = vec[0].size();
	for(auto &item:vec){
		size = std::min(size,int(item.size()));
		std::reverse(item.begin(),item.end());
	}
//	std::cout << size << std::endl;
	for(int i=0;i<size;i++){
		bool equ = true;
		char c = vec[0][i];
		for(auto &item:vec){
			if(c != item[i]){
				equ = false;
			}
		}
		if(equ){
			str.push_back(c);
		}else{
			break;
		}
	}
	if(str.empty()){
		std::cout << "nai" << std::endl;
	}else{
		std::reverse(str.begin(),str.end());
		std::cout << str << std::endl;
	}
	
	return 0;
}

/*
1077. Kuchiguse (20)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
HOU, Qiming
The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:

Itai nyan~ (It hurts, nyan~)
Ninjin wa iyada nyan~ (I hate carrots, nyan~)
Now given a few lines spoken by the same character, can you find her Kuchiguse?

Input Specification:

Each input file contains one test case. For each case, the first line is an integer N (2<=N<=100). Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.

Output Specification:

For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write "nai".

Sample Input 1:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
Sample Output 1:
nyan~
Sample Input 2:
3
Itai!
Ninjinnwaiyada T_T
T_T
Sample Output 2:
nai
*/
