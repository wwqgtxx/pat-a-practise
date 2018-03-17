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

void adjust(std::multiset<int> &s1,std::multiset<int> &s2,int &mid){
	if (s1.size()<s2.size()){
		auto it = s2.begin();
		s1.insert(*it);
		s2.erase(it);
	}
	if (s1.size()>s2.size()+1){
		auto it=s1.end();
		it--;
		s2.insert(*it);
		s1.erase(it);
	}
	if (!s1.empty()){
		auto it=s1.end();
		it--;
		mid = *it;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::vector<int> stack;
	std::multiset<int> s1,s2;
	int mid = 1e5*2;
	std::vector<int> vec;
	int n;
	std::cin >> n;
	std::string str;
	int num;
	std::stringstream ss;
	for(int i=0;i<n;i++){
		std::cin >> str;
		if(str == "Pop"){
			if(stack.empty()){
				ss << "Invalid" << std::endl;
			}else{
				num = stack.back();
				ss << num << std::endl;
				stack.pop_back();
				if (num<=mid){
					s1.erase(s1.find(num));
				}else{
					s2.erase(s2.find(num));
				} 
				adjust(s1,s2,mid);
			}
		}else if(str == "PeekMedian"){
			if(stack.empty()){
				ss << "Invalid" << std::endl;
			}else{
				ss << mid << std::endl;
			}
			
		}else{
			std::cin >> num;
			stack.emplace_back(num);
			if (num<=mid){
				s1.emplace(num);
			}else{
				s2.emplace(num);
			} 
			adjust(s1,s2,mid);
		}
	}
//	str = ss.str();
	std::cout << ss.str();
} 

/*
1057. Stack (30)
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
Stack is one of the most fundamental data structures, which is based on the principle of Last In First Out (LIFO). The basic operations include Push (inserting an element onto the top position) and Pop (deleting the top element). Now you are supposed to implement a stack with an extra operation: PeekMedian -- return the median value of all the elements in the stack. With N elements, the median value is defined to be the (N/2)-th smallest element if N is even, or ((N+1)/2)-th if N is odd.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<= 105). Then N lines follow, each contains a command in one of the following 3 formats:

Push key
Pop
PeekMedian
where key is a positive integer no more than 105.

Output Specification:

For each Push command, insert key into the stack and output nothing. For each Pop or PeekMedian command, print in a line the corresponding returned value. If the command is invalid, print "Invalid" instead.

Sample Input:
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop
Sample Output:
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid
*/
