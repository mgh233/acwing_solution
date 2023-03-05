#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int s, t;
struct Range{
    int l, r;
    bool operator<(const Range &w)const {
        return l < w.l;
    }
}range[N];

int main() {
    scanf("%d%d", &s, &t);
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++) {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }

    sort(range, range + n);

    int res = 0;
    bool success = false;
    for (int i = 0; i < n; i ++) {
        int j = i, r = -2e9;
        // 找到左端点小于s的区间的最大右端点
        while (j < n && range[j].l <= s) {
            r = max(r, range[j].r);
            j ++;
        }

        // 没有找到最大右端点则不存在
        if (r < s) {
            res = -1;
            break;
        }

        res ++;
        // 右端点已超过区间右端点则提前退出
        if (r >= t) {
            success = true;
            break;
        }
        
        s = r; // 更新区间左端点
        i = j - 1; // 从上一轮结束处开始遍历，j-1是因为出循环时还要加1
    }
    
    if (!success) res = -1;
    cout << res;

    return 0;
}