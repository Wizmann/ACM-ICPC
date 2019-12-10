import sys
from collections import defaultdict

N = 1500000

def gcd(a, b):
    if a % b == 0:
        return b 
    return gcd(b, a % b)

d = defaultdict(int)

for i in xrange(1, N):
    if i * i >= N:
        break
    for j in xrange(1, i):
        if gcd(i, j) != 1:
            continue
        if (i + j) % 2 != 1:
            continue
        a = i * i + j * j
        b = i * i - j * j
        c = 2 * i * j

        key = a + b + c
        base = key

        while key <= N:
            d[key] += 1
            key += base

tot = 0
for key, value in d.items():
    if value == 1:
        tot += 1
print tot
