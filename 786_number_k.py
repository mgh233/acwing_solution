def quick_sort(ls, l, r):
    if l >= r:
        return
    x = ls[(l + r) >> 1]
    i = l - 1
    j = r + 1
    while i < j:
        i = i + 1
        while ls[i] < x:
            i = i + 1
        j = j - 1
        while ls[j] > x:
            j = j - 1
        if i < j:
            ls[i], ls[j] = ls[j], ls[i]
    quick_sort(ls, l, j)
    quick_sort(ls, j + 1, r)


[n, k] = [eval(x) for x in input().split()]
ls = [eval(x) for x in input().split()]
quick_sort(ls, 0, n - 1)
print(ls[k - 1])