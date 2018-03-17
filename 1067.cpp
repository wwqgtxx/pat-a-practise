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

typedef std::vector<int>::iterator it_t;

int check(int start,const it_t &begin,const it_t &end){
	for(int i=start; begin+i < end ;i++){
		if(begin[i] != i){
			return i;
		}
	}
	return 0;
}

int main(){
	int n;
	std::cin >> n;
	std::vector<int> vec(n);
	for(int i=0;i<n;i++){
		std::cin >> vec[i];
	}
	int count = 0;
	auto begin = vec.begin();
	auto end = vec.end();
	int pos = check(1,begin,end);
	while(pos){
		if(vec[0] == 0){
//			std::cout << "0swap(" << vec[0] << ',' << vec[pos] << ')' << std::endl;
			std::swap(vec[0],vec[pos]);
			count++;
		}
		while(vec[0] != 0){
//			std::cout << "1swap(" << vec[0] << ',' << vec[vec[0]] << ')' << std::endl;
			std::swap(vec[0],vec[vec[0]]);
			count++;
		}
		pos = check(pos,begin,end);
	}
	std::cout << count << std::endl;
	return 0;
}
/*
1067. Sort with Swap(0,*) (25)
ʱ������
150 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Yue
Given any permutation of the numbers {0, 1, 2,..., N-1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}

Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

Input Specification:

Each input file contains one test case, which gives a positive N (<=105) followed by a permutation sequence of {0, 1, ..., N-1}. All the numbers in a line are separated by a space.

Output Specification:

For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

Sample Input:
10 3 5 7 2 6 4 9 0 8 1
Sample Output:
9
*/

/*
�����˼·�������뵽����������ע�ؼ��ɻᳬʱ��
��������v[]����������Ԫ�أ�����Ŀ��Ŀ�ľ���ͨ�����ٵĽ���������ע��ֻ�ܱ�����0����һ����������
��ʹ�ö�������i����v[i]== i,��ȻҪ������ٽ����������Ǿ͸þ���ʹÿһ�ν���������һ��Ԫ�ر�������ȷλ��
���Ҹ�Ԫ�ز����ٴα������������������������ۣ�
1. v[0] != 0:
   ˵��0������ȷλ���ϣ���Ҫͨ���任ʹ��v[0] == 0���С���ʱ�ý�0��ô���0������λ���ϵ�Ԫ�ؽ���
��������������ľ���{4, 0, 2, 1, 3}����ʱ�ý�0��1��0������λ�����Ϊ1�����Ȿ����1���ڵ�λ�ã�������
ͨ�����ƵĶ�ν���ֱ��v[0] == 0;
2. v[0] == 0:
 ��ʱ0������ȷλ�����ˣ�������Ԫ�ػ�û��ȫ������ȷλ�á����Ա������һ�ηϽ����ˣ���������û
��ʹһ��Ԫ�ص�����ȷλ�ã�����ô�������϶����ܽ�0��һ���Ѵ�����ȷλ�õ�Ԫ�ؽ����ɣ�Ҫ�����ý����Ԫ��
���������������Կ϶��ǽ�0��һ�����ڲ���ȷλ�õ�Ԫ�ؽ�����

�и��ؼ����������ж�����Ľ����� ע�⵽������Ҫ�õ�����λ�õ�Ԫ�أ�������һ������ÿ�δ�λ��1��ʼ�Ҵ���Ԫ�أ�����Ҳ�������0��ע�ⲻҪ��0��ʼ�ң�����ֻҪ�ҵ���λ�ò���0����˵������δ��������Ԫ�أ������0��ʼ�ң����޷��ж��Ƿ���������ˣ���Ϊ������0�ж��Ƿ��Ҳ������������ǲ��ص��ĵ�һ������λ����0��������������0��0λ�õ�����δ��ɵ�������������д���

����˵�ıȽ��ң��ܽ����£�

�ٴ�λ��1��ʼ���Ҵ���λ�ã��Ҳ�������0���ҵ�������Ӧλ�á�

��������Һ�������0��˵�����������ֱ�ӽ������������ۡ�

�����0�Ѿ���λ����������û�н��������0�����޷�����������ʱ����0������õ��Ĵ���λ�ý�������������������ý�������������С�

����0û�й�λ������£����ϵذ�0��λ�ú�Ӧ�������λ�õ�Ԫ�ؽ�����ֱ��0��λ����ʱ����ͨ���ٵĲ����ж��Ƿ������û�н������ټ����ۡ��ܣ�ֱ�������Ҳ�������λ�á�
*/
