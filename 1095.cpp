#include<cstdio>
#include<cmath>
#include<cstring>
#include<stdint.h>
#include<algorithm>
#include<set>
#include<iostream>
#include<iomanip>
#include<vector>
#include<stack>
#include<map>

struct Time {
    int hh;
    int mm;
    int ss;

    operator int() const{
        return hh*3600+mm*60+ss;
    }

    Time operator-(const Time &other) const {
        Time time1 = *this;
        time1.ss -= other.ss;
        if (time1.ss < 0) {
            time1.ss += 60;
            time1.mm--;
        }
        time1.mm -= other.mm;
        if (time1.mm < 0) {
            time1.mm += 60;
            time1.hh--;
        }
        time1.hh -= other.hh;
        return time1;
    }

    Time operator+(const Time &other) const {
        Time time1 = *this;
        time1.ss += other.ss;
        if (time1.ss >= 60) {
            time1.ss -= 60;
            time1.mm++;
        }
        time1.mm += other.mm;
        if (time1.mm >= 60) {
            time1.mm -= 60;
            time1.hh++;
        }
        time1.hh += other.hh;
        return time1;
    }

    bool operator<(const Time &other) const {
        if (hh < other.hh) {
            return true;
        } else if (hh == other.hh) {
            if (mm < other.mm) {
                return true;
            } else if (mm == other.mm) {
                if (ss < other.ss) {
                    return true;
                }
            }
        }
        return false;
    }

    bool operator>(const Time &other) const {
        return other < *this;
    }

    bool operator<=(const Time &other) const {
        return !(*this > other);
    }

    bool operator>=(const Time &other) const {
        return !(*this < other);
    }

    bool operator!=(const Time &other) const {
        return (*this < other) || (*this > other);
    }

    bool operator==(const Time &other) const {
        return !(*this != other);
    }
};

std::map<std::string, std::set<std::pair<Time, bool> > > map;
std::vector<Time> time_vec;
std::vector<int> num_vec;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    char str1[8], str2[4];
    memset(str1, 0, sizeof(str1));
    memset(str2, 0, sizeof(str2));
    Time time;
    for (int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d %s", &str1, &time.hh, &time.mm, &time.ss, &str2);
        map[str1].insert(std::make_pair(time, str2[0] == 'i'));
    }
    time_vec.resize(k);
    num_vec.resize(k);
    for (int i = 0; i < k; i++) {
        Time &time = time_vec[i];
        scanf("%d:%d:%d", &time.hh, &time.mm, &time.ss);
    }
    std::vector<std::string> longest_vec;
    Time longest_time{0, 0, 0};
    for (std::map<std::string, std::set<std::pair<Time, bool> > >::iterator it = map.begin();
         it != map.end();) {
        std::set<std::pair<Time, bool> > &set = it->second;
        std::set<std::pair<Time, bool> >::iterator it1 = set.begin(), it2 = ++set.begin();
        while (it2 != set.end()) {
            if (it1->second && it2->second) {//in+in remove begin
                it2++;
                set.erase(it1++);
                continue;
            }
            if (!it1->second && !it2->second) {//out+out remove second
                set.erase(it2++);
                continue;
            }
            it1++;
            it2++;
        }
        while (!set.empty()) {
            if (!set.begin()->second) {//start with out
                set.erase(set.begin());
            } else {
                break;
            }
        }
        while (!set.empty()) {
            if ((--set.end())->second) {//end with in
                set.erase(--set.end());
            } else {
                break;
            }
        }
        if (set.size() < 2) {
            map.erase(it++);
        } else {
            it1 = set.begin(), it2 = ++set.begin();
            Time time1{0, 0, 0};
            while (it2 != set.end()) {
                time1 = time1 + (it2->first - it1->first);
                std::vector<Time>::iterator it3 = std::lower_bound(time_vec.begin(),time_vec.end(),it1->first),//*it3>=it1->first
                        it4 = std::lower_bound(time_vec.begin(),time_vec.end(),it2->first);//*it4>=it2->first (!!!*it4!=it2->first!!!)
                for(;it3!=it4;it3++){
                    num_vec[it3-time_vec.begin()]++;
                }
                it1++;
                it2++;
                if (it2 == set.end()) {
                    break;
                }
                it1++;
                it2++;
            }
            if (time1 > longest_time) {
                longest_vec.clear();
                longest_time = time1;
            }
            if (time1 >= longest_time) {
                longest_vec.push_back(it->first);
            }
            it++;
        }
    }
    for (int i = 0; i < k; i++) {
        printf("%d\n", num_vec[i]);
    }
    for (int i = 0; i < longest_vec.size(); i++) {
        printf("%s ", longest_vec[i].c_str());
    }
    printf("%02d:%02d:%02d\n", longest_time.hh, longest_time.mm, longest_time.ss);
    return 0;
}
//    for (std::map<std::string, std::set<std::pair<Time, bool> > >::iterator it = map.begin();
//         it != map.end();it++) {
//        std::set<std::pair<Time, bool> > &set = it->second;
//        std::set<std::pair<Time, bool> >::iterator it1 = set.begin(), it2 = ++set.begin();
//        Time time1{0, 0, 0};
//        while (it2 != set.end()) {
//            if(it1->second && !it2->second){//in+out
//                time1 = time1 + (it2->first - it1->first);
//                for(int t1=it1->first,t2=it2->first;t1<t2;t1++){
//                    arr[t1]++;
//                }
//                it1++;
//                it2++;
//                if(it2 == set.end(){
//                    break;
//                }
//            }
//            it1++;
//            it2++;
//        }
//        if (time1 > longest_time) {
//            longest_vec.clear();
//            longest_time = time1;
//        }
//        if (time1 >= longest_time) {
//            longest_vec.push_back(it->first);
//        }
//    }
/*
1095 Cars on Campus （30 分）
Zhejiang University has 8 campuses and a lot of gates. From each gate we can collect the in/out times and the plate numbers of the cars crossing the gate. Now with all the information available, you are supposed to tell, at any specific time point, the number of cars parking on campus, and at the end of the day find the cars that have parked for the longest time period.

Input Specification:
Each input file contains one test case. Each case starts with two positive integers N (≤10
?4
?? ), the number of records, and K (≤8×10
?4
?? ) the number of queries. Then N lines follow, each gives a record in the format:

plate_number hh:mm:ss status
where plate_number is a string of 7 English capital letters or 1-digit numbers; hh:mm:ss represents the time point in a day by hour:minute:second, with the earliest time being 00:00:00 and the latest 23:59:59; and status is either in or out.

Note that all times will be within a single day. Each in record is paired with the chronologically next record for the same car provided it is an out record. Any in records that are not paired with an out record are ignored, as are out records not paired with an in record. It is guaranteed that at least one car is well paired in the input, and no car is both in and out at the same moment. Times are recorded using a 24-hour clock.

Then K lines of queries follow, each gives a time point in the format hh:mm:ss. Note: the queries are given in accending order of the times.

Output Specification:
For each query, output in a line the total number of cars parking on campus. The last line of output is supposed to give the plate number of the car that has parked for the longest time period, and the corresponding time length. If such a car is not unique, then output all of their plate numbers in a line in alphabetical order, separated by a space.

Sample Input:
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00
Sample Output:
1
4
5
2
1
0
1
JH007BD ZD00001 07:20:09
作者: CHEN, Yue
单位: 浙江大学
时间限制: 300 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/

