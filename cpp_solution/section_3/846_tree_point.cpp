#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
const int M = N * 2;

int n;
int h[N], e[M], ne[M], idx;
bool st[N];

int ans = N;

//在a点所对应的链表中插入b
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

//深度优先搜索，返回以u为根的子树的节点的数量
int dfs(int u) {
    st[u] = true; //标记一下，已经被搜索过了

    int sum = 1, res = 0; // res是把该点删除后每一个连通块大小的最大值
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum); //删除u节点后会将树分为三个部分：u的两个子树以及剩下的树的部分（大小为n - sum）

    ans = min(ans, res);

    return sum;
}

int main() {
    cin >> n;
    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1);

    cout << ans << endl;

    return 0;
}