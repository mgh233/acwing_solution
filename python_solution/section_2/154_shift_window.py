[n, k] = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
q = []
for i in range(n):
    if len(q) and i - k + 1 > q[0]:
        q.pop(0)
    while len(q) and a[q[-1]] >= a[i]:
        q.pop()
    q.append(i)
    if i >= k - 1:
        print(a[q[0]], end=" ")
print("")
q = []
for i in range(n):
    if len(q) and i - k + 1 > q[0]:
        q.pop(0)
    while len(q) and a[q[-1]] <= a[i]:
        q.pop()
    q.append(i)
    if i >= k - 1:
        print(a[q[0]], end=" ")