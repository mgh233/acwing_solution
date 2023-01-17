segs = []


def merge(segs):
    res = []
    segs.sort()

    st = -2e9 
    ed = -2e9
    for seg in segs:
        if ed < seg[0]:
            if st != -2e9:
                res.append([st, ed])
            st = seg[0]
            ed = seg[1]
        else:
            ed = max(ed, seg[1])
    if st != -2e9:
        res.append([st, ed])
    return res



n = int(input())
for i in range(n):
    segs.append([int(x) for x in input().split()])
segs = merge(segs)
print(len(segs))