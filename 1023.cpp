#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

int main(){
	std::string num;
	std::cin >> num;
	std::vector<char> used(num.size(),0);
	int over = 0;
	std::string num2;
	for(auto it=num.rbegin();it!=num.rend();it++){
		int n = *it - '0';
		n *= 2;
		n += over;
		over = n/10;
		n -= over*10;
		num2.push_back(n + '0');
	}
	if(over>0){
		num2.push_back(over + '0');
	}
	std::reverse(num2.begin(),num2.end());
	bool ok=true;
	for(auto it=num2.begin();it!=num2.end();it++){
		bool find=false;
		for(int i=0;i<num.size();i++){
			if(num[i] == *it){
				if(!used[i]){
					used[i] = 1;
					find=true;
					break;
				}
			}
		}
		if(!find){
			ok = false;
			break;
		}
	}
	if(ok){
		std::cout << "Yes" << std::endl;
	}else{
		std::cout << "No" << std::endl;
	}
	std::cout << num2 << std::endl;
} 

/*
1023. Have Fun with Numbers (20)
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
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

Input Specification:

Each input file contains one test case. Each case contains one positive integer with no more than 20 digits.

Output Specification:

For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.

Sample Input:
1234567899
Sample Output:
Yes
2469135798
*/
