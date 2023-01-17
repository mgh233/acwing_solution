[n, m] = [int(x) for x in input().split()]
ls = [int(x) for x in input().split()]
sum = []
for i in range(n + 1):
    if i == 0:
        sum.append(0)
        continue
    sum.append(ls[i - 1] + sum[i - 1])
while m:
    [l, r] = [int(x) for x in input().split()]
    print(sum[r] - sum[l - 1])
    m -= 1