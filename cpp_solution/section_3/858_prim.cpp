#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N]; // 稠密图
int dist[N]; // 存储点到集合的最短距离（区别于dijkstra算法）
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i ++) {
        int t = -1;
        for (int j = 1; j <= n; j ++) { //找到集合外距离集合最短的点
            if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }
        if (i && dist[t] == INF) return INF; // 不是第一个点但最短距离为无穷，说明不是连通图
        if (i) res += dist[t]; //由于在i=0时dist数组并未更新，所以dist[1]理论上的0实际为INF

        for (int j = 1; j <= n; j ++) {
            dist[j] = min(dist[j], g[t][j]);
        }

        st[t] = true;

    }
    return res;
}

int main() {
    scanf ("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);

    while (m --) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();

    if (t == INF) puts("impossible");
    else printf("%d", t);

    return 0;
}