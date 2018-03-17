#include<iostream> 
#include<string>
#include<sstream>

int main(){
	int a,b;
	std::cin >> a >> b;
	std::stringstream ss;
	ss << a+b;
	std::string str = ss.str();
	int n=0;
	for(int i=str.length()-1;i>=0;i--){
		if(str[i]== '-'){
			break;
		}
		n++;
		if(n==4){
			str.insert(i+1,",");
			n = 1;
		}
	}
	std::cout << str << std::endl;
	return 0;	
}

/*
1001. A+B Format (20)
ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Yue
Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9
Sample Output
-999,991
*/ 