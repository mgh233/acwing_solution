#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 310;

int n, m;
int h[N][N]; // 高度
int f[N][N]; // 状态

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dp(int x, int y) {
    int &v = f[x][y];
    if (v != -1) return v;

    v = 1;
    for (int i = 0; i < 4; i ++) {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 1 && a <= n && b >= 1 && b <= m && h[a][b] < h[x][y])
            v = max(v, dp(a, b) + 1);
    }

    return v;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            scanf("%d", &h[i][j]);
        }
    }

    memset(f, -1, sizeof f); // 初始化，表示每个点都还没被算过
    
    int res = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            res = max(res, dp(i ,j)); // dp(i, j)返回f[i][j]
        }
    }
    
    cout << res;
    return 0;
}