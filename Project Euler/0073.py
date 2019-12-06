import sys
import itertools

N = 12000

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

cnt = 0
for i in xrange(2, N + 1):
    for j in xrange(1, i):
        if gcd(i, j) != 1:
            continue
        if 1.0 / 3 < 1.0 * j / i < 1.0 / 2:
            cnt += 1
print cnt
