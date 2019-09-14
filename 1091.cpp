#include<cstdio>
#include<cmath>
#include<stdint.h>
#include<algorithm>
#include<set>
#include<iostream>
#include<iomanip>
#include<vector>
#include<stack>

const size_t MAX = 1290 * 130 * 64;
bool arr[MAX];
int m, n, l, t;

inline bool &get(const int16_t &x, const int16_t &y, const int16_t &z) {
    if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) {
        arr[MAX - 1] = false;
        return arr[MAX - 1];
    }
    return arr[x * n + y + z * n * m];
}

struct point_t {
    int16_t x;
    int16_t y;
    int16_t z;

    point_t(const int16_t &x, const int16_t &y, const int16_t &z) : x(x), y(y), z(z) {}

    point_t() : x(0), y(0), z(0) {}

    inline bool &get() const {
        return ::get(x, y, z);
    }

    point_t operator+(const point_t &point) {
        point_t point1;
        point1.x = x + point.x;
        point1.y = y + point.y;
        point1.z = z + point.z;
        return point1;
    }
};

int count;
point_t dir[6] = {point_t(+1, 0, 0),
                  point_t(-1, 0, 0),
                  point_t(0, +1, 0),
                  point_t(0, -1, 0),
                  point_t(0, 0, +1),
                  point_t(0, 0, -1)};

std::stack<point_t> stack;

void dfs(const point_t &point_begin) {
    if (point_begin.get()) {
        point_begin.get() = false;
        count++;
        stack.push(point_begin);
        while (!stack.empty()) {
            point_t point = stack.top();
            stack.pop();
            for (int i = 0; i < 6; i++) {
                point_t new_point = point + dir[i];
                if (new_point.get()) {
                    new_point.get() = false;
                    count++;
                    stack.push(new_point);
                }
            }
        }
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> m >> n >> l >> t;
    int result = 0;
    point_t point;
    for (point.z = 0; point.z < l; point.z++) {
        for (point.x = 0; point.x < m; point.x++) {
            for (point.y = 0; point.y < n; point.y++) {
                std::cin >> point.get();
            }
        }
    }
    for (point.z = 0; point.z < l; point.z++) {
        for (point.x = 0; point.x < m; point.x++) {
            for (point.y = 0; point.y < n; point.y++) {
                count = 0;
                dfs(point);
                if (count >= t) {
                    result += count;
                }
            }
        }
    }
    std::cout << result << std::endl;
}

/*
1091 Acute Stroke （30 分）
One important factor to identify acute stroke (急性脑卒中) is the volume of the stroke core. Given the results of image analysis in which the core regions are identified in each MRI slice, your job is to calculate the volume of the stroke core.

Input Specification:
Each input file contains one test case. For each case, the first line contains 4 positive integers: M, N, L and T, where M and N are the sizes of each slice (i.e. pixels of a slice are in an M×N matrix, and the maximum resolution is 1286 by 128); L (≤60) is the number of slices of a brain; and T is the integer threshold (i.e. if the volume of a connected core is less than T, then that core must not be counted).

Then L slices are given. Each slice is represented by an M×N matrix of 0's and 1's, where 1 represents a pixel of stroke, and 0 means normal. Since the thickness of a slice is a constant, we only have to count the number of 1's to obtain the volume. However, there might be several separated core regions in a brain, and only those with their volumes no less than T are counted. Two pixels are connected and hence belong to the same region if they share a common side, as shown by Figure 1 where all the 6 red pixels are connected to the blue one.

【插图】

Figure 1

Output Specification:
For each case, output in a line the total volume of the stroke core.

Sample Input:
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
Sample Output:
26
作者: CHEN, Yue
单位: 浙江大学
时间限制: 600 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/


