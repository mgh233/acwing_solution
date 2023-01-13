[n, m] = [int(x) for x in input().split()]
N = 300010
a = [0] * N
s = [0] * N
alls = []
add = []
query = []

def find(x):
    l = 0
    r = len(alls) - 1
    while l < r:
        mid = l + r >> 1
        if alls[mid] >= x:
            r = mid
        else:
            l = mid + 1
    return r + 1

for i in range(n):
    [x, c] = [int(x) for x in input().split()]
    add.append((x, c))
    alls.append(x)
for i in range(m):
    [l, r] = [int(x) for x in input().split()]
    query.append((l, r))
    alls.append(l)
    alls.append(r)

# 去重
alls = list(set(alls))
alls.sort()

for item in add:
    x = find(item[0])
    a[x] += item[1]
    
for i in range(1, len(alls) + 1):
    s[i] = s[i - 1] + a[i]

for item in query:
    l = find(item[0])
    r = find(item[1])
    print(s[r] - s[l - 1])