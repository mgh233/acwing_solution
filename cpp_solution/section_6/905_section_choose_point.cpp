#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

int n;
struct Range {
    int l, r;
    bool operator <(const Range &w)const {
        return r < w.r;
    }
}range[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }

    sort(range, range + n);

    int res = 0, ed = -2e9; // ed表示上一个选择的点的下标
    for (int i = 0; i < n; i ++) {
        if (range[i].l > ed) { // 如果上一个选择的点不在该区间范围内
            res ++;
            ed = range[i].r;
        }
    }

    cout << res;
    return 0;
}