#include <iostream>
#include <algorithm>

using namespace std;

const int N =110;

int n;
int a[N][N];

int gauss() {
    int r, c;
    for (r = c = 0; c < n; c ++) {
        int t = r;
        for (int i = r; i < n; i ++) {
            if (a[i][c]) { // 找非零行
                t = i;
                break;
            }
        }
        if (!a[t][c]) continue; //没找到非零行

        for (int i = c; i <= n; i ++) { // 换行
            swap(a[t][i], a[r][i]);
        }

        for (int i = r + 1; i < n; i ++) { // 将下面的行消成0，直接异或即可
            if (a[i][c])
                for (int j = c; j <= n; j ++) {
                    a[i][j] ^= a[r][j];
                }
        }

        r ++;
    }

    if (r < n) {
        for (int i = r; i < n; i ++) {
            if (a[i][n]) return 2;
        }
        return 1;
    }

    for (int i = n - 1; i >= 0; i --) {
        for (int j = i + 1; j < n; j ++) {
            a[i][n] ^= a[i][j] * a[j][n];
        }
    }

    return 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n + 1; j ++) {
            cin >> a[i][j];
        }
    }

    int res = gauss();

    if (res == 0) {
        for (int i = 0; i < n; i ++) cout << a[i][n] << endl;
    }
    else if (res == 1) puts("Multiple sets of solutions");
    else puts("No solution");

    return 0;
}