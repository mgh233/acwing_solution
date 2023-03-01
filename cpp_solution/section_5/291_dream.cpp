#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 12, M = 1 << N;

int n, m;
long long f[N][M]; // 第一维表示列，第二维表示所有可能的状态
bool st[M]; // 存储每种状态是否有奇数个连续的0，如果奇数个连续的0则为无效状态，存false，反之为true

int main() {
    while (cin >> n >> m, n || m) { // 读到输入0和0时表示结束即为终止
        memset(f, 0, sizeof f);

        // 预处理是否有奇数个0，遍历每种状态
        for (int i = 0; i < 1 << n; i ++) {
            st[i] = true; // 先存储为true
            int cnt = 0; // 记录连续0的个数
            for (int j = 0; j < n; j ++) { // 遍历这一列的每一行
                if (i >> j & 1) { // 若为1则说明该行有横向放置的块
                    if (cnt & 1) st[i] = false; // 若先前所记录的连续0的个数为奇数，则存储状态为false
                    cnt = 0; // 初始化cnt
                }
                else cnt ++; // 若不为1则该列未放置横向的块，cnt加1
            }

            if (cnt & 1) st[i] = false; // 把可能剩下的行判断一下
        }

        f[0][0] = 1; // 最开始只有一种方案
        for (int i = 1; i <= m; i ++) { // 遍历每一列
            for (int j = 0; j < 1 << n; j ++) { // 遍历当前列的所有状态
                for (int k = 0; k < 1 << n; k ++) { // 遍历i-1列的所有状态
                    if ((j & k) == 0 && st[j | k]) { // j & k所得的结果表示这一列与前一列横向放置的块是否有重叠，j | k表示当前这一列最终所占用的格子数，需要满足连续0为偶数个
                        f[i][j] += f[i - 1][k];
                    }
                }
            }
        }
        cout << f[m][0] << endl; //由于第m列肯定没有横着放的块，所以最终答案就为前m-1列处理完毕后第m列状态为0的值
    }
    
    return 0;
}