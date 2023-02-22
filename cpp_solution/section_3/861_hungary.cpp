#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N]; // 相当于临时预定数组，st[j] = a表示右半部分的j已经被左半部分a预定了

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i]; // 找到左半部分对应的右半部分的点
        if (!st[j]) { // 还未被预定
            st[j] = true;
            // j未匹配到左半部分的点或者所匹配到的点有其他人选时
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d%d", &n1, &n2, &m);

    memset(h, -1, sizeof h);

    while (m --) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    int res = 0;
    for (int i = 1; i <= n1; i ++) {
        memset(st, false, sizeof st); // 每轮匹配的预定情况不一样所以需要初始化
        if (find(i)) res ++;
    }

    printf("%d", res);
    return 0;
}