#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 6010;

int n;
int happy[N]; // 每个人的高兴度
int h[N], e[N], ne[N], idx; // 用邻接表存储树
int f[N][2]; // 存储状态
bool has_father[N]; // 是否有父节点

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u) {
    f[u][1] = happy[u]; // 选了自己就将自己的快乐指数加上
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i]; // 得到儿子
        dfs(j);

        f[u][0] += max(f[j][0], f[j][1]); // 不选当前节点，则它的儿子可选可不选，取最大即可
        f[u][1] += f[j][0]; // 选了当前节点，则它的儿子都不能选
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &happy[i]);

    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        scanf("%d%d", &a, &b);
        has_father[a] = true;
        add(b, a);
    }
    
    int root = 1;
    while (has_father[root]) root ++; // 找到根节点

    dfs(root);

    cout << max(f[root][0], f[root][1]);

    return 0;
}