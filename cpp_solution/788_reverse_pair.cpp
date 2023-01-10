#include <iostream>

using namespace std;

const int N = 100010;

int q[N], tmp[N];

long reverse_pair(int q[], int l, int r) {
    if (l >= r) return 0;

    int mid = l + r >> 1;
    long num = reverse_pair(q, l, mid) + reverse_pair(q, mid + 1, r);
    
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) {
            tmp[k++] = q[i++];
        }
        else{
            tmp[k++] = q[j++];
            num += mid - i + 1;
        }
    }
    while (i <= mid) {
        tmp[k++] = q[i++];
    }
    while (j <= r) {
        tmp[k++] = q[j++];
    }
    for (int i = l, j = 0; i <= r; i++, j++) {
        q[i] = tmp[j];
    }
    return num;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }
    printf("%ld", reverse_pair(q, 0, n - 1));
    return 0;
}