#include <iostream>
#include <string>

using namespace std;

const int N = 100010;

int stk[N], tt = -1;

int main() {
    int m;
    string s;
    cin >> m;
    while (m --) {
        cin >> s;
        if (s == "push") {
            int x;
            cin >> x;
            stk[++tt] = x;
        }
        else if (s == "pop") {
            tt --;
        }
        else if (s == "empty") {
            if (tt == -1) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
        else {
            printf("%d\n", stk[tt]);
        }
    }

    return 0;
}