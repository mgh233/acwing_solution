[n, m] = [int(x) for x in input().split()]
ls = [0] + [int(x) for x in input().split()]
diff = []
for i in range(n + 1):
    if i == 0:
        diff.append(0)
        continue
    diff.append(ls[i] - ls[i - 1])
while m:
    [l, r, c] = [int(x) for x in input().split()]
    diff[l] += c
    if r + 1 < len(diff):
        diff[r + 1] -= c
    m -= 1
for i in range(1, n + 1):
    ls[i] = diff[i] + ls[i - 1]
    print(ls[i], end=' ')