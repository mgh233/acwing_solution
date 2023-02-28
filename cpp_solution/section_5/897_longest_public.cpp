#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s%s", a + 1, b + 1); // 由于用到了i-1，所以下标从1开始
    
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++){
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1); // 因为a[i]和b[j]都出现在公共序列，所以须相等
        }
    
    cout << f[n][m] << endl;

    return 0;
}