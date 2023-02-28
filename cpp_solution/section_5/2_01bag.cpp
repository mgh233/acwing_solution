#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N]; // v表示体积，w表示价格
int f[N]; // 状态

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i ++) 
        for (int j = m; j >= v[i]; j --) { // 因为f[0][0~m]=0，所以从1开始初始化
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }

    cout << f[m] << endl;

    return 0;
}