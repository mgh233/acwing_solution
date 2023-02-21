#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 150010;

int n, m, idx;
int h[N], w[N], e[N], ne[N];
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist); // 初始化距离
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap; // 定义小根堆
    heap.push({0, 1});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first; // 堆中的点通过（距离，编号）存储
        if (st[ver]) continue; // 若该点已经写入s则跳过
        st[ver] = true; // 更新状态

        for (int i = h[ver]; i != -1; i = ne[i]) { // 更新距离
            int j = e[i];
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    
    if (dist[n] == 0x3f3f3f3f) {
        return -1;
    }
    return dist[n];
}

int main() {
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    while (m --) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b ,c);
    }
    int t = dijkstra();

    printf("%d\n", t);
    return 0;
}