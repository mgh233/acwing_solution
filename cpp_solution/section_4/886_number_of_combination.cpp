#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 100010, mod = 1e9 + 7;

int fact[N], infact[N]; // 阶乘和阶乘的逆元

int qmi(int a, int k, int p) { // 快速幂
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int main() {
    fact[0] = infact[0] = 1; // 0！= 1
    for (int i = 1; i < N; i ++) { // 计算阶乘
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod; //逆元的定义
    }

    int n;
    cin >> n;
    while (n --) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n",(LL)fact[a] * infact[b] % mod * infact[a - b] % mod);
    }

    return 0;
}