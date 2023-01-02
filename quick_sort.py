def quick_sort(l, r):
    if l >= r:
        return
    global ls
    x = ls[(l + r) // 2]
    i = l - 1
    j = r + 1
    while i < j:
        i = i + 1
        j = j - 1
        while ls[i] < x:
            i = i + 1
        while ls[j] > x:
            j = j - 1
        if i < j:
            ls[i], ls[j] = ls[j], ls[i]
    quick_sort(l, j)
    quick_sort(j + 1, r)


n = eval(input())
ls = [eval(x) for x in input().split()]
quick_sort(0, n - 1)
for x in ls:
    print(x, end=" ")