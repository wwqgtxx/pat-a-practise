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

int main(){
	int n;
	std::cin >> n;
	int count = 0;
	int x = 1;
	while(n/x>0){
		int right = n%x;
		int nx = n/x;
		int left = nx/10;
		int current = nx%10;
		if(current == 0){
			count += left * x;
		}else if(current == 1){
			count += left * x + right + 1;
		}else{
			count += (left+1) * x ;
		}
		x *= 10; 
	}
	std::cout << count << std::endl;
}

/*
�ֱ���ÿһλ����1��������������

ѭ�����ǵ�ǰλ����λ����λ

�����ǰλ==0�����Ϊ����1 ������ɸ���λ������= ����Ϊ����*��ǰλ��

�����ǰλ==1�����Ϊ����1 ������ܸ���λ�Լ���λӰ�죬= ������Ϊ����*��ǰλ����+����λ����+1��

�����ǰλ>1�����Ϊ����1 ������ɸ���λ������= (����Ϊ����+1)*��ǰλ��
*/

/*
1049. Counting Ones (30)
ʱ������
100 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Yue
The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

Input Specification:

Each input file contains one test case which gives the positive N (<=230).

Output Specification:

For each test case, print the number of 1's in one line.

Sample Input:
12
Sample Output:
5
*/
