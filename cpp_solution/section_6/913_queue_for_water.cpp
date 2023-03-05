#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n; // 总人数
int t[N]; // 每个同学的打水时间
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &t[i]);
    }

    sort(t, t + n);

    LL res = 0;
    for (int i = 0; i < n; i ++) res += t[i] * (n - i - 1);

    cout << res;
    return 0;
}