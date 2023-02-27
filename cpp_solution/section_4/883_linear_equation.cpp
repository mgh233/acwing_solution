#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-6;

int n;
double a[N][N];

int guass() {
    int c, r; // 第c列第r行
    for (c = 0, r = 0; c < n; c ++) {
        int t = r;
        for (int i = r; i < n; i ++) { // 找到绝对值最大的那一行
            if (fabs(a[i][c]) > fabs(a[t][c])) {
                t = i;
            }
        }
        if (fabs(a[t][c]) < eps) continue; // 说明有一个变量无法确定

        for (int i = c; i <= n; i ++) { // 与第r行交换
            swap(a[t][i], a[r][i]);
        }
        for (int i = n; i >= c; i --) {
            a[r][i] /= a[r][c]; // 将第c列的数变为1
        }
        for (int i = r + 1; i < n; i ++) { // 将下面所有行的第c列变为0
            if (fabs(a[i][c]) > eps) {
                for (int j = n; j >= c; j --) {
                    a[i][j] -= a[r][j] * a[i][c];
                }
            }
        }

        r ++;
    }

    if (r < n) { // 存在变量前系数为0的情况
        for (int i = r; i < n; i ++) {
            if (fabs(a[i][n]) > eps) {
                return 2; //如果等式右边非零说明无解
            }
        }
        return 1; //有无穷解
    }

    for (int i = n - 1; i >= 0; i --) { //计算结果
        for (int j = i + 1; j < n; j ++) {
            a[i][n] -= a[i][j] * a[j][n];
        }
    }

    return 0; //有唯一解
}

int main() {
    cin >> n; 
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n + 1; j ++) {
           cin >> a[i][j];
        }
    }

    int t = guass();

    if (t == 0) {
        for (int i = 0; i < n; i ++) {
            if (fabs(a[i][n]) < eps) a[i][n] = 0.00;
            printf("%.2f\n", a[i][n]);
        }
    }
    else if (t == 1) printf("Infinite group solutions");
    else printf("No solution");

    return 0;
}