#include <iostream>
#include <algorithm>

using namespace std;

int n;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / i; i ++) { // sqrt操作慢，不推荐
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int a;
    scanf("%d", &n);
    while (n --) {
        scanf("%d", &a);
        if (is_prime(a)) puts("Yes");
        else puts("No");
    
    }

    return 0;
}