[n, m, q] = [int(x) for x in input().split()]
ls = []
sum = []
for i in range(n):
    ls.append([int(x) for x in input().split()])
for i in range(n + 1):
    if i == 0:
        sum.append([0 for i in range(m + 1)])
        continue
    sum.append([])
    for j in range(m + 1):
        if j == 0:
            sum[i].append(0)
            continue
        sum[i].append(sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + ls[i - 1][j - 1])
while q:
    [x1, y1, x2, y2] = [int(x) for x in input().split()]
    print(sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1])
    q -= 1