#include <iostream>

using namespace std;

const int N = 100010, M = N * 31;

int a[N], son[M][2], idx;

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i --) {
        int u = x >> i & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int search(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i --) {
        int u = x >> i & 1;
        if (son[p][!u]) //如果当前层有对应的不同的数
        {
            p = son[p][!u];
            res = res * 2 + 1;
        }
        else {
            p = son[p][u];
            res = res * 2 + 0;
        }
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i ++) {
        res = max(res, search(a[i]));
    }
    printf("%d", res);
}