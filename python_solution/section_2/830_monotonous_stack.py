stk = []

n = int(input())
ls = [int(x) for x in input().split()]
for i in range(n):
    while len(stk) and stk[-1] >= ls[i]:
        stk.pop()
    if len(stk):
        print(stk[-1], end=" ")
    else:
        print(-1, end=" ")
    stk.append(ls[i])