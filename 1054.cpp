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
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int m,n,t;
	std::cin >> m >> n;
	std::map<int,int> map;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			std::cin >> t;
			map[t]++;
		}
	}
	int max_item = 0;
	int max_value = 0;
	for(auto &item:map){
//		std::cout << item.first << ' ' << item.second << std::endl;
		if(item.second > max_value){
			max_value = item.second;
			max_item = item.first;
		}
	}
	std::cout << max_item << std::endl;
	return 0;
}

/*
1054. The Dominant Color (20)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Behind the scenes in the computer's memory, color is always talked about as a series of 24 bits of information for each pixel. In an image, the color with the largest proportional area is called the dominant color. A strictly dominant color takes more than half of the total area. Now given an image of resolution M by N (for example, 800x600), you are supposed to point out the strictly dominant color.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive numbers: M (<=800) and N (<=600) which are the resolutions of the image. Then N lines follow, each contains M digital colors in the range [0, 224). It is guaranteed that the strictly dominant color exists for each input image. All the numbers in a line are separated by a space.

Output Specification:

For each test case, simply print the dominant color in a line.

Sample Input:
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24
Sample Output:
24
*/
