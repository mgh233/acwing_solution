def merge_sort(ls):
    if len(ls) <= 1:
        return

    mid = len(ls) >> 1
    L = ls[:mid]
    R = ls[mid:]
    merge_sort(L)
    merge_sort(R)

    i = 0
    j = 0
    k = 0
    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            ls[k] = L[i]
            i = i + 1
        else:
            ls[k] = R[j]
            j = j + 1
        k = k + 1
    while i < len(L):
        ls[k] = L[i]
        i = i + 1
        k = k + 1
    while j < len(R):
        ls[k] = R[j]
        j = j + 1
        k = k + 1


n = eval(input())
ls = [eval(x) for x in input().split()]
merge_sort(ls)
for i in ls:
    print(i, end=' ')
