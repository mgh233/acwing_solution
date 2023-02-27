#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 20;

int n, m;
int p[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) cin >> p[i]; // 输入质数

    int res = 0;
    for (int i = 1; i < 1 << m; i ++) { // 枚举到2^m-1，求出所有可能的组合
        int t = 1, cnt = 0; // t为当前所有质数的乘积，cnt为包含几个集合
        for (int j = 0; j < m; j ++) { // 从0开始枚举m位
            if (i >> j & 1) { //当前这一位是1
                cnt ++;
                if ((LL)t * p[j] > n) {
                    t = -1;
                    break;
                }
                t *= p[j];
            }
        }
        
        if (t != -1) {
            // n/t表示能够整除t的集合的大小
            if (cnt % 2) res += n / t; // 根据容斥原理，奇数个集合应该加上
            else res -= n / t;
        }
    }

    cout << res << endl;

    return 0;
}