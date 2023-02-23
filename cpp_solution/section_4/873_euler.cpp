#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n --) {
        int a;
        cin >> a;

        int res = a;
        for (int i = 2; i <= a / i; i ++) {
            if (a % i == 0) {
                res = res / i * (i - 1); // res / i * (i - 1)等价于res * (1 - 1 / i)，由于不能有小数所以使用前者
                while (a % i == 0) a /= i;
            }
        }
        if (a > 1) res = res / a * (a - 1);

        cout << res << endl;
    }
    
    return 0;
}