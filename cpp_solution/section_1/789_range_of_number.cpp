#include <iostream>

using namespace std;

const int N = 100010;

int a[N];

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    while(q--) {
        int number;
        scanf("%d", &number);
        int l = 0, r = n - 1, mid = 0;
        while(l < r) {
            mid = l + r >> 1;
            if(a[mid] >= number) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        if (a[l] != number) {
            cout << "-1 -1" << endl;
        }
        else {
            cout << l << " ";
            l = 0;
            r = n - 1;
            while(l < r) {
                mid = l + r + 1 >> 1;
                if(a[mid] <= number) {
                    l = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            cout << l << endl;
        }

    }
    return 0;
}