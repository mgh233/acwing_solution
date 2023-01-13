def lowbit(x):
    return x & -x


n = int(input())
ls = [int(x) for x in input().split()]


for i in range(n):
    res = 0
    x = ls[i]
    while x:
        x -= lowbit(x)
        res += 1
    print(res, end=" ")