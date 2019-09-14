#include<cstdio>
#include<stdint.h>
#include<algorithm>
#include<set>

const int N_MAX=40000;
const int M_MAX=100;
const int K_MAX=5;

int N,M,K;

struct applicant_t{
	int id;
	int64_t ge;
	int64_t gi;
	int64_t gf;
	int ks[K_MAX];
	
	bool operator < (const applicant_t &other) const {
		if(gf<other.gf){
			return true;
		}else if(gf==other.gf){
			if(ge<other.ge){
				return true;
			}
		}
		return false;
	}
	
	bool operator > (const applicant_t &other) const {
		if(gf>other.gf){
			return true;
		}else if(gf==other.gf){
			if(ge>other.ge){
				return true;
			}
		}
		return false;
	}
	
	bool operator == (const applicant_t &other) const {
		return gf==other.gf&&ge==other.ge;
	}
};

applicant_t applicants[N_MAX];

struct school_t{
	int quota;
	applicant_t* last_applicant;
	std::set<int> admitted;
};

school_t schools[M_MAX];

int main(){
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++){
		school_t &school = schools[i];
		scanf("%d",&school.quota);
		school.last_applicant = 0;
	}
	for(int i=0;i<N;i++){
		applicant_t &applicant = applicants[i];
		applicant.id = i;
		scanf("%d%d",&applicant.ge,&applicant.gi);
		for(int j=0;j<K;j++){
			scanf("%d",&applicant.ks[j]);
		}
		applicant.gf = applicant.ge+applicant.gi;
	}
	std::sort(applicants,applicants+N,std::greater<applicant_t>());
	for(int i=0;i<N;i++){
		applicant_t &applicant = applicants[i];
		for(int j=0;j<K;j++){
			int &school_id = applicant.ks[j];
			school_t &school = schools[school_id];
			if(
				(school.last_applicant!=0 && ((*school.last_applicant)==applicant))//same rank
			||	(school.quota > 0)//different rank
			){
				school.quota--;
				school.last_applicant = &applicant;
				school.admitted.insert(applicant.id);
				break;
			}
		}
	}
	for(int i=0;i<M;i++){
		school_t &school = schools[i];
		for(std::set<int>::iterator it=school.admitted.begin();it!=school.admitted.end();it++){
			if(it!=school.admitted.begin()){
				printf(" ");
			}
			printf("%d",*it);
		}
		printf("\n");
	}
}
/*
1080 Graduate Admission （30 分）
It is said that in 2011, there are about 100 graduate schools ready to proceed over 40,000 applications in Zhejiang Province. It would help a lot if you could write a program to automate the admission procedure.

Each applicant will have to provide two grades: the national entrance exam grade GE, and the interview grade GI. The final grade of an applicant is (GE+GI)/2. The admission rules are:

The applicants are ranked according to their final grades, and will be admitted one by one from the top of the rank list.

If there is a tied final grade, the applicants will be ranked according to their national entrance exam grade GE. If still tied, their ranks must be the same.

Each applicant may have K choices and the admission will be done according to his/her choices: if according to the rank list, it is one's turn to be admitted; and if the quota of one's most preferred shcool is not exceeded, then one will be admitted to this school, or one's other choices will be considered one by one in order. If one gets rejected by all of preferred schools, then this unfortunate applicant will be rejected.

If there is a tied rank, and if the corresponding applicants are applying to the same school, then that school must admit all the applicants with the same rank, even if its quota will be exceeded.

Input Specification:
Each input file contains one test case.

Each case starts with a line containing three positive integers: N (≤40,000), the total number of applicants; M (≤100), the total number of graduate schools; and K (≤5), the number of choices an applicant may have.

In the next line, separated by a space, there are M positive integers. The i-th integer is the quota of the i-th graduate school respectively.

Then N lines follow, each contains 2+K integers separated by a space. The first 2 integers are the applicant's GE and GI, respectively. The next K integers represent the preferred schools. For the sake of simplicity, we assume that the schools are numbered from 0 to M-1, and the applicants are numbered from 0 to N-1.

Output Specification:
For each test case you should output the admission results for all the graduate schools. The results of each school must occupy a line, which contains the applicants' numbers that school admits. The numbers must be in increasing order and be separated by a space. There must be no extra space at the end of each line. If no applicant is admitted by a school, you must output an empty line correspondingly.

Sample Input:
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4
Sample Output:
0 10
3
5 6 7
2 8

1 4
作者: CHEN, Yue
单位: 浙江大学
时间限制: 250 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
