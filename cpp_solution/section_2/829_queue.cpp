#include <iostream>
#include <string>

using namespace std;

const int N = 100010;

int que[N], hh = 0, tt = -1;

int main() {
    int m;
    cin >> m;
    while (m --) {
        string s;
        cin >> s;
        if (s == "push") {
            int x;
            cin >> x;
            que[++tt] = x;
        }
        else if (s == "pop") {
            hh ++;
        }
        else if (s == "empty") {
            if (hh > tt) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else {
            cout << que[hh] << endl;
        }
    }
    return 0;
}