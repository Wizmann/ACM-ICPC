INF = 0x3f3f3f3f
tax = [
    (0   ,     0),
    (1500,  0.03),
    (4500,  0.10),
    (9000,  0.20),
    (35000, 0.25),
    (55000, 0.30),
    (80000, 0.35),
    (INF,   0.45)
]

def calc_tax(value):
    n = len(tax)
    res = 0
    value -= 3500
    for i in xrange(1, n):
        (a, v) = tax[i]
        pre = tax[i - 1][0]
        if value > a:
            res += (a - pre) * v
        else:
            res += (value - pre) * v
            break
    return res

assert calc_tax(15692) == 2043

    
value = int(raw_input())
l, r = 0, INF

while l <= r:
    m = (l + r) >> 1
    if calc_tax(m) > value:
        r = m - 1
    else:
        l = m + 1
print r
