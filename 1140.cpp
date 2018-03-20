#include<cstdio>
#include<bits/stdc++.h>

int main(){
	int d,n;
	scanf("%d%d",&d,&n);
	std::string str;
	str.push_back(d+'0');
	std::stringstream ss;
	for(int i=0;i<n-1;i++){
		ss.str("");
		ss.clear();
		char last_c = str[0];
		int c_num = 1;
		for(int j=1;j<str.size();j++){
			if(str[j] != last_c){
				ss << last_c << c_num;
				last_c = str[j];
				c_num = 1;
			}else{
				c_num++;
			}
		}
		ss << last_c << c_num;
		str = ss.str();
//		std::cout << str << std::endl;
	}
	printf("%s\n",str.c_str());
	return 0;
}

/*
1140. Look-and-say Sequence (20)
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
Look-and-say sequence is a sequence of integers as the following:

D, D1, D111, D113, D11231, D112213111, ...
where D is in [0, 9] except 1. The (n+1)st number is a kind of description of the nth number. For example, the 2nd number means that there is one D in the 1st number, and hence it is D1; the 2nd number consists of one D (corresponding to D1) and one 1 (corresponding to 11), therefore the 3rd number is D111; or since the 4th number is D113, it consists of one D, two 1's, and one 3, so the next number must be D11231. This definition works for D = 1 as well. Now you are supposed to calculate the Nth number in a look-and-say sequence of a given digit D.

Input Specification:

Each input file contains one test case, which gives D (in [0, 9]) and a positive integer N (<=40), separated by a space.

Output Specification:

Print in a line the Nth number in a look-and-say sequence of D.

Sample Input:
1 8
Sample Output:
1123123111
*/
