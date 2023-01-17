a = []
b = []


def insert(x1, y1, x2, y2, c):
    b[x1][y1] += c
    b[x2 + 1][y1] -= c
    b[x1][y2 + 1] -= c
    b[x2 + 1][y2 + 1] += c


[n, m, q] = [int(x) for x in input().split()]
for i in range(n + 1):
    if i == 0:
        a.append([])
        for j in range(m + 1):
            a[0].append(0)
        continue
    a.append([0] + [int(x) for x in input().split()])

b = [[0] * (m + 2) for i in range(n + 2)]
for i in range(1, n + 1):
    for j in range(1 , m + 1):
        insert(i, j, i, j, a[i][j])
        
while q:
    [x1, y1, x2, y2, c] = [int(x) for x in input().split()]
    insert(x1, y1, x2, y2, c)
    q -= 1

for i in range(1, n + 1):
    for j in range(1, m + 1):
        a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + b[i][j]
        print(a[i][j], end=" ")
    print("")