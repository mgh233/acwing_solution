#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N], f[N], g[N]; // g保存最长序列

int main () {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i ++) {
        f[i] = 1; // 只有a[i]一个数(最极端情况)
        g[i] = 0;
        for (int j = 1; j < i; j ++) {
            if (a[j] < a[i]) {
                if (f[i] < f[j] + 1) {
                    f[i] = f[j] + 1;
                    g[i] = j; // 记录从哪个状态转移而来
                }
            }
        }
    }
    int k = 1;
    for (int i = 1; i <= n; i ++) 
        if (f[k] < f[i])
            k = i;

    cout << f[k] << endl;

    // 倒序输出最长序列
    for (int i = 0, len = f[k]; i < len; i ++) {
        cout << a[k] << " ";
        k = g[k];
    }
    return 0;
}