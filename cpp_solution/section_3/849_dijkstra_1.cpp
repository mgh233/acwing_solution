#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;
int g[N][N];
int dist[N]; // 存储1号点到其他点的最短距离
bool st[N]; // 存储该点是否已有最短路（是否在s中）

int dijkstra() {
    memset(dist, 0x3f, sizeof dist); // 初始化距离
    dist[1] = 0;

    for (int i = 0; i < n; i ++) {
        int t = 0;
        for (int j = 1; j <= n; j ++) { // 找到不在s中的距离最近的点
            if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }
        
        st[t] = true;

        for (int j = 1; j <= n; j++) { //更新距离
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if (dist[n] == 0x3f3f3f3f) {
        return -1;
    }
    else return dist[n];
}

int main() {
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);

    while (m --) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    int t = dijkstra();

    printf("%d\n", t);
    return 0;
}