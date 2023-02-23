#include <iostream>

using namespace std;

typedef long long LL;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0; // b = 0时，最大公约数为a本身，此时x=1, y=0时满足条件
        return a;
    }
    int d =  exgcd(b, a % b, y, x); // 换一下是因为要和a，b对应

    y -= a / b * x;
    return d;
}

int main() {
    int n;
    scanf("%d", &n);

    while (n --) {
        int a, b, m;
        scanf("%d%d%d", &a, &b, &m);
        int x, y;
        int d = exgcd(a, m, x ,y);
        if (b % d) puts("impossible");
        else printf("%d\n", (LL) x * (b / d) % m);
    }
}