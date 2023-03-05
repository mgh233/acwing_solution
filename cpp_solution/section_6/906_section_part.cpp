#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n;
struct Range {
    int l, r;
    bool operator<(const Range &w) {
        return l < w.l;
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

    // 小根堆存储各组最大的右端点值
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; i ++) {
        auto r = range[i];
        // 如果堆是空或堆中各组最大右端点的最小值大于当前区间的左端点，由于区间是根据左端点进行排序，
        // 所以该区间的左端点一定比heap中区间的左端点大。综合以上两个条件，可以判断得出该区间无法放入任何一个组中
        if (heap.empty() || heap.top() >= r.l) heap.push(r.r);
        else {// 更新最大右端点
            int t = heap.top();
            heap.pop();
            heap.push(r.r);
        }
    }

    cout << heap.size();
    return 0;
}