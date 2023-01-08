def reverse_pair(ls):
    if len(ls) <= 1:
        return 0

    mid = len(ls) >> 1
    L = ls[:mid]
    R = ls[mid:]
    n = reverse_pair(L) + reverse_pair(R)

    i = j = k = 0
    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            ls[k] = L[i]
            i += 1
        else:
            ls[k] = R[j]
            j += 1
            n += len(L) - i  # 关键点
        k += 1
    while i < len(L):
        ls[k] = L[i]
        i += 1
        k += 1
    while j < len(R):
        ls[k] = R[j]
        j += 1
        k += 1
    return n


length = int(input())
ls = [int(x) for x in input().split()]
num = reverse_pair(ls)
print(num)