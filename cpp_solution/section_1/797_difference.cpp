#include <iostream>

using namespace std;

const int N = 100010;

int p[N], diff[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++) {
        diff[i] = p[i] - p[i - 1];
    }
    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        diff[l] += c;
        diff[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++) {
        p[i] = diff[i] + p[i - 1];
        printf("%d ", p[i]);
    }
    return 0;
}