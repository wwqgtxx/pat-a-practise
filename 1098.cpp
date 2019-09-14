#include<cstdio>
#include<stdint.h>
#include<algorithm>
#include<set>
#include<iostream>
#include<vector>

std::vector<int> vec_raw;
std::vector<int> vec_to;
std::vector<int> vec;
int n;
bool flag = false;

void output() {
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            std::cout << ' ';
        }
        std::cout << vec[i];
    }
    std::cout << std::endl;
}

void insertion_sort() {
    for (int i = 1; i < n; i++) {
        int num = vec[i];
        int j = 0;
        for (; j < i; j++) {
            if (vec[j] > num) {
                vec.erase(vec.begin() + i);
                vec.insert(vec.begin() + j, num);
                break;
            }
        }
        if (flag) {
            output();
            return;
        }
        if (vec == vec_to) {
            std::cout << "Insertion Sort" << std::endl;
            flag = true;
        }
    }
}


void heap_adjust(int length, int k) {
    int tmp = vec[k];
    int i = 2 * k + 1;
    while (i < length) {
//        -----------------
//        小顶堆
//        if (i + 1 < length && vec[i] > vec[i + 1]) //选取最小的结点位置
//            ++i;
//        if (tmp < vec[i]) //不用交换
//            break;
//        -----------------

//        -----------------
//        大顶堆
        if (i + 1 < length && vec[i] < vec[i + 1]) //选取最大的结点位置
            ++i;
        if (tmp > vec[i]) //不用交换
            break;
//        -----------------
        vec[k] = vec[i]; //交换值
        k = i; //继续查找
        i = 2 * k + 1;
    }
    vec[k] = tmp;
}

void heap_sort() {
    if (vec.empty())
        return;
    for (int i = n / 2 - 1; i >= 0; --i) {
        heap_adjust(n, i); //从第二层开始建堆
    }

    for (int i = n - 1; i >= 0; --i) {
        std::swap(vec[0], vec[i]);
        heap_adjust(i, 0); //从顶点开始建堆, 忽略最后一个
        if (flag) {
            output();
            return;
        }
        if (vec == vec_to) {
            std::cout << "Heap Sort" << std::endl;
            flag = true;
        }
    }
}

void merge(int start, int mid, int end) {
    std::vector<int> tmp;
    int start1 = start;
    int start2 = mid;
    while (start1 < mid && start2 < end) {
        if (vec[start1] < vec[start2]) {
            tmp.push_back(vec[start1++]);
        } else {
            tmp.push_back(vec[start2++]);
        }
    }
    while (start1 < mid) {
        tmp.push_back(vec[start1++]);
    }
    while (start2 < end) {
        tmp.push_back(vec[start2++]);
    }
    for (int i = 0; start != end;) {
        vec[start++] = tmp[i++];
    }
}

void merge_sort() {
    for (int i = 1; i < n; i *= 2) {
        int i2 = i * 2;
        int j = 0;
        for (; j + i2 <= n; j += i2) {
            merge(j, j + i, j + i2);
        }
        if (j + i < n) {
            merge(j, j + i, n);
        }
        if (flag) {
            output();
            return;
        }
        if (vec == vec_to) {
            std::cout << "Merge Sort" << std::endl;
            flag = true;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    vec_raw.resize(n);
    vec_to.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vec_raw[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> vec_to[i];
    }
    vec = vec_raw;
    merge_sort();
    if (!flag) {
        vec = vec_raw;
        heap_sort();
    }
    if (!flag) {
        vec = vec_raw;
        insertion_sort();
    }

}
/*
1098 Insertion or Heap Sort （25 分）
According to Wikipedia:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

Heap sort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region. it involves the use of a heap data structure rather than a linear-time search to find the maximum.

Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in the first line either "Insertion Sort" or "Heap Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
Sample Output 2:
Heap Sort
5 4 3 1 0 2 6 7 8 9
作者: CHEN, Yue
单位: 浙江大学
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
