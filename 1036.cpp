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

int main(){
	int n;
	std::cin >> n;
	std::string name,id;
	char fm;
	int grade;
	std::string f_name,f_id,m_name,m_id;
	int f_grade = -1,m_grade = 101;
	for(int i=0;i<n;i++){
		std::cin >> name >> fm >> id >> grade;
		if(fm == 'M'){
			if(grade < m_grade){
				m_grade = grade;
				m_name = name;
				m_id = id;
			}
		}else{
			if(grade > f_grade){
				f_grade = grade;
				f_name = name;
				f_id = id;
			}
		}
	}
	if(f_grade == -1){
		std::cout << "Absent" << std::endl;
	}else{
		std::cout << f_name << ' ' << f_id << std::endl;
	}
	if(m_grade == 101){
		std::cout << "Absent" << std::endl;
	}else{
		std::cout << m_name << ' ' << m_id << std::endl;
	}
	if(f_grade == -1 || m_grade == 101){
		std::cout << "NA" << std::endl;
	}else{
		std::cout << f_grade - m_grade << std::endl;
	}
}
/*
1036. Boys vs Girls (25)
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
This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N, followed by N lines of student information. Each line contains a student's name, gender, ID and grade, separated by a space, where name and ID are strings of no more than 10 characters with no space, gender is either F (female) or M (male), and grade is an integer between 0 and 100. It is guaranteed that all the grades are distinct.

Output Specification:

For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference gradeF-gradeM. If one such kind of student is missing, output "Absent" in the corresponding line, and output "NA" in the third line instead.

Sample Input 1:

3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95
Sample Output 1:
Mary EE990830
Joe Math990112
6
Sample Input 2:
1
Jean M AA980920 60
Sample Output 2:
Absent
Jean AA980920
NA

*/
