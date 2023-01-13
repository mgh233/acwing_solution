N = 100010
n = int(input())
a = [int(x) for x in input().split()]
s = [0] * N
j = 0
res = 0
for i in range(n):
    s[a[i]] += 1
    while s[a[i]] > 1:
        s[a[j]] -= 1
        j += 1
    res = max(res, i - j + 1)
print(res)