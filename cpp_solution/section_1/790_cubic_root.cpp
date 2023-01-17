#include <iostream>

using namespace std;

int main() {
    double n;
    cin >> n;
    double l = 0.0, r, mid;
    if (n < 1 && n > 0) {
        r = 1;
    }
    else if (n < 0 && n > -1) {
        r = -1;
    }
    else {
        r = n;
    }
    if (n > 0) {
        while(r - l > 10e-8){
            mid = (l + r) / 2;
            if (mid * mid * mid > n) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
    }
    else {
        while(l - r > 10e-8){
            mid = (l + r) / 2;
            if (mid * mid * mid < n) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
    }
    printf("%.6f", l);
}