#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int res = 0, i = 1;
    cin >> n;
    
    while (n --) {
        int x;
        scanf("%d", &x);
        if (i % 2) res ^= x;
        i ++;
    }

    if (res) puts("Yes");
    else puts("No");

    return 0;
}