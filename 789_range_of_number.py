def b_search(ls, number, n):
    i = 0
    j = n - 1
    while i < j:
        mid = i + j >> 1
        if ls[mid] >= number:
            j = mid
        else:
            i = mid + 1
    if ls[i] != number:
        return -1, -1
    else:
        l = i
        i = 0
        j = n - 1
        while i < j:
            mid = i + j + 1 >> 1
            if ls[mid] <= number:
                i = mid
            else:
                j = mid - 1
        r = i
    return l, r


[n, q] = [int(x) for x in input().split()]
ls = [int(x) for x in input().split()]
for i in range(q):
    number = int(input())
    l, r = b_search(ls, number, n)
    print(l, r)