#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int a[N];
int q[N]; // 存储不同长度上升子序列结尾的最小值

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);

    int len = 0; // 上升子序列最长的长度
    q[0] = -2e9;
    // 遍历所有数
    for (int i = 0; i < n; i ++) {
        int l = 0, r = len;
        while (l < r) { // 找到比a[i]小的最大值处
            int mid =  l + r + 1>> 1;
            if (q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1); // 更新长度
        q[r + 1] = a[i]; // 把a[i]接到r后面
    }
    cout << len << endl;

    return 0;
}