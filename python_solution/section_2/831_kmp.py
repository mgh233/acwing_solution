n = int(input())
p = '0' + input()
m = int(input())
s = '0' + input()
ne = [0] * (n + 1)
# 求next
j = 0
for i in range(2, n + 1):
    while j and p[i] != p[j + 1]:
        j = ne[j]
    if p[i] == p[j + 1]:
        j += 1
    ne[i] = j

# kmp匹配
j = 0
for i in range(1, m + 1):
    while j and s[i] != p[j + 1]:
        j = ne[j]
    if s[i] == p[j + 1]:
        j += 1
    if j == n:
        print(i - n, end=" ")
        j = ne[j]
