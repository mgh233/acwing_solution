N = 100010

idx = 2
e = [0] * N
l = [0] * N
r = [0] * N

r[0] = 1
l[1] = 0


def add(k, x):
    global idx, e, l, r
    e[idx] = x
    r[idx] = r[k]
    l[idx] = k
    l[r[k]] = idx
    r[k] = idx
    idx += 1

def remove(k):
    global idx, e, l, r
    r[l[k]] = r[k]
    l[r[k]] = l[k]


m = int(input())
while m:
    op = [x for x in input().split()]
    if op[0] == 'L':
        add(0, int(op[1]))
    elif op[0] == 'R':
        add(l[1], int(op[1]))
    elif op[0] == 'D':
        remove(int(op[1]) + 1)
    elif op[0] == 'IL':
        add(l[int(op[1]) + 1], int(op[2]))
    else:
        add(int(op[1]) + 1, int(op[2]))
    m -= 1

i = r[0]
while i != 1:
    print(e[i], end=" ")
    i = r[i]