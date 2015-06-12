def factors(n, x):
    res = 0
    i = x
    while i <= n:
        res += n / i
        i *= x
    return res

n = int(raw_input())

n2 = factors(n, 2)
n5 = factors(n, 5)

print min(n2, n5)
