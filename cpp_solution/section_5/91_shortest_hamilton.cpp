#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20, M = 1 << N;

int n;
int w[N][N];
int f[M][N]; // 状态，第一维表示经过点的二进制记录，第二维表示到达哪个点

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> w[i][j];
        }
    }

    memset(f, 0x3f, sizeof f);
    f[1][0] = 0; // 处于起始点
    // 枚举状态
    for (int i = 0; i < 1 << n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (i >> j & 1) // 因为最后一位为j，所以i中代表j的点需要为1，否则无意义
                for (int k = 0; k < n; k ++) { // 上一个点
                    if ((i - (1 << j)) >> k & 1) // i除去j这个点之后需要包含k这个点
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
                }
        }
    }
    cout << f[(1 << n) - 1][n - 1] << endl;

    return 0;
}