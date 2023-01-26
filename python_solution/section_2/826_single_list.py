N = 100010

head = -1
idx = 0
e = [0] * N
ne = [0] * N

def add_to_head(x):
    global idx, head, e, ne
    e[idx] = x
    ne[idx] = head
    head = idx
    idx += 1

def add(k, x):
    global idx, head, e, ne
    e[idx] = x
    ne[idx] = ne[k]
    ne[k] = idx
    idx += 1

def remove(k):
    global idx, head, e, ne
    ne[k] = ne[ne[k]]

m = int(input())
while m:
    op = [x for x in input().split()]
    if op[0] == 'H':
        add_to_head(int(op[1]))
    elif op[0] == 'D':
        if int(op[1]) == 0:
            head = ne[head]
        else:
            remove(int(op[1]) - 1)
    else:
        add(int(op[1]) - 1, int(op[2]))
    m -= 1

i = head
while i != -1:
    print(e[i], end=" ")
    i = ne[i]