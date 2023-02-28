#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 1e9;

int n;
int a[N][N]; // 三角形中的点
int f[N][N]; // 状态

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j ++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j <= i + 1; j ++) { // 每行多初始化一个，因为最右边计算时会涉及到外部不存在的点需要初始化为-∞
            f[i][j] = -INF;
        }
    }
    f[1][1] = a[1][1];
    for (int i = 2; i <= n; i ++) {
        for (int j = 1; j <= i; j ++) {
            f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);
        }
    }
    int res = -INF;
    for (int i = 1; i <= n; i ++) {
        res = max(res, f[n][i]);
    }

    cout << res << endl;

    return 0;
}