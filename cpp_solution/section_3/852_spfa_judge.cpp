#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 150010;

int n, m, idx;
int h[N], w[N], e[N], ne[N];
int dist[N], cnt[N]; // cnt表示到达该点最小距离所经历的边数
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int spfa() {
    memset(dist, 0x3f, sizeof dist); // 初始化距离
    dist[1] = 0;

    queue<int> q;
    for (int i = 1; i <= n; i ++) { //将所有点都放入队列，因为可能会存在有负环的路径不经过1号点的情况
        st[i] = true;
        q.push(i);
    }

    while (q.size()) {
        int t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1; //更新边数

                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    while (m --) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b ,c);
    }

    if (spfa()) puts("Yes");
    else printf("No");
    return 0;
}