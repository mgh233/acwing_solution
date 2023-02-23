#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL) res * a % p; // k最后一位为1时将a % p乘入
        k >>= 1;
        a = (LL) a * a % p; // 预处理中的项的规律为下一项是这一项的平方
    }
    return res;
}

int main() {
    int n;
    scanf ("%d", &n);

    while (n --) {
        int a, k, p;
        scanf("%d%d%d", &a, &k, &p);

        printf("%d\n", qmi(a, k, p));
    }
}