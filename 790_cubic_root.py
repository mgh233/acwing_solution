def cubic_root(number):
    i = 0
    if 0 < number < 1:
        j = 1
    elif -1 < number < 0:
        j = -1
    else:
        j = number
    if number > 0:
        while j - i > 10e-8:
            mid = (i + j) / 2
            if mid * mid * mid > number:
                j = mid
            else:
                i = mid
    else:
        while i - j > 10e-8:
            mid = (i + j) / 2
            if mid * mid * mid < number:
                j = mid
            else:
                i = mid
    return i


n = float(input())
print("{:.6f}".format(cubic_root(n)))