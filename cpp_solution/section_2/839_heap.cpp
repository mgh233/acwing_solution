#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N = 100010;

int h[N], ph[N], hp[N], Size;

void heap_swap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u) {
    int t = u;
    if (u * 2 <= Size && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= Size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u) {
    while (u / 2 && h[u / 2] > h[u]) {
        heap_swap(u / 2, u);
        u /= 2;
    }
}

int main() {
    int n, m = 0;
    scanf("%d", &n);
    
    while (n --) {
        char op[10];
        int k, x;

        scanf("%s", op);
        if (!strcmp(op, "I")) {
            scanf("%d", &x);
            Size ++;
            m ++;
            ph[m] = Size, hp[Size] = m;
            h[Size] = x;
            up(Size);
        }
        else if (!strcmp(op, "PM")) printf("%d\n", h[1]);
        else if (!strcmp(op, "DM")) {
            heap_swap(1, Size);
            Size --;
            down(1);
        }
        else if (!strcmp(op, "D")) {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, Size);
            Size --;
            down(k), up(k);
        }
        else {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }

    return 0;
}