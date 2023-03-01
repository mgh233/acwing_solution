#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 求从l到r位组成的数为多少
int get(vector<int> num, int l, int r) {
    int res = 0;
    for (int i = l; i >= r; i --) {
        res = res * 10 + num[i];
    }
    return res;
}

// 求10的x次方
int power10(int x) {
    int res = 1;
    while (x --) res *= 10;
    return res;
}

int count(int n, int x) {
    if (!n) return 0;
    
    vector<int> num;
    // 提取每一位
    while (n) {
        num.push_back(n % 10);
        n /= 10;
    }

    n = num.size();

    int res = 0;
    // 从最高位开始讨论
    for (int i = n - 1 - !x; i >= 0; i --) {
        // 第(1)种情况（若枚举的最高位则不存在，所以判断一下即可）
        if (i < n - 1) {
            res += get(num, n - 1, i + 1) * power10(i);
            if (!x) res -= power10(i); // 若x为0，前面为全零的情况需要减去
        }

        // 第(2)种情况
        if (num[i] == x) res += get(num, i - 1, 0) + 1;
        else if (num[i] > x) res += power10(i);
    }

    return res;
}

int main() {
    int a, b;
    while (cin >> a >> b, a || b) {
        if (a > b) swap(a, b); // 小数在前，大数在后
        for (int i = 0; i < 10; i ++) {
            cout << count(b, i) - count(a - 1, i) << " ";
        }
        cout << endl;
    }

    return 0;
}