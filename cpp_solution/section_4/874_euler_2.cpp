#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1000010;

int primes[N], cnt;
int phi[N];
bool st[N];

LL get_eulers(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i ++) {
        if (!st[i]) {
            primes[cnt ++] = i;
            phi[i] = i - 1; // 质数n跟1～n-1全互质
        }
        for (int j = 0; primes[j] <= n / i; j ++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                // i * primes[j]的质因子与i的质因子相同，计算primes[j] * i的公式中除了primes[j]一项
                // 的其余项就等于phi[i]
                phi[primes[j] * i] = primes[j] * phi[i];
                break;
            }
            else {
                // i % primes[j] != 0，表示primes[j]是i * primes[j]的最小质因子
                // 但primes[j]不是i的质因子，所以相较于前面的情况这里需要再乘上一个(1 - 1 / primes[j])
                // 该项与primes[j]相消得到(primes[j] - 1)项
                phi[primes[j] * i] = phi[i] * (primes[j] - 1);
            }
        }
    }

    LL res = 0;
    for (int i = 1; i <= n; i ++) {
        res += phi[i];
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    cout << get_eulers(n) << endl;

    return 0;
}