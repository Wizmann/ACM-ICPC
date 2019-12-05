import sys
import itertools

def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

def lcm(a, b):
    g = gcd(a, b)
    return a * b / g

def test(a1, b1, a2, b2):
    c = lcm(b1, b2)
    a1 *= c / b1
    a2 *= c / b2
    return a1 - a2

N = 1000000

a, b = 0, 1

for i in xrange(2, N):
    if i == 7:
        continue
    l, r = 1, i - 1
    while l <= r:
        m = (l + r) / 2
        if test(m, i, 3, 7) >= 0:
            r = m - 1
        else:
            l = m + 1
    if r > 0 and test(r, i, a, b) >= 0:
        a, b = r, i
c = gcd(a, b)
print a / c, b / c
