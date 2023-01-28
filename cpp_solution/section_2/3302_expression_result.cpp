#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

const int N = 100010;

int a[N], att = -1, ott = -1;
char op[N];

//优先级表
unordered_map<char, int> h{ {'+', 1}, {'-', 1}, {'*',2}, {'/', 2} };

void eval() {
    char p = op[ott--];
    int c = a[att--];
    int b = a[att--];
    if (p == '+') a[++att] = b + c;
    else if (p == '-') a[++att] = b - c;
    else if (p == '*') a[++att] = b * c;
    else if (p == '/') a[++att] = b / c;
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i ++) {
        if (isdigit(s[i])) {
            int value = 0;
            while (i < s.size() && isdigit(s[i])) {
                value *= 10;
                value += s[i] - '0';
                i ++;
            }
            a[++att] = value;
            i -= 1;
        }
        else if (s[i] == '(') {
            op[++ott] = s[i];
        }
        else if (s[i] == ')') {
            while (op[ott] != '(') {
                eval();
            }
            ott --;
        }
        else {
            while (ott != -1 && h[op[ott]] >= h[s[i]]) {
                eval();
            }
            op[++ott] = s[i];
        }
    }
    while (ott != -1) {
        eval();
    }
    cout << a[att];

    return 0;
}