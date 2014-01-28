from math import sqrt
from itertools import permutations

ans = 0
def is_prime(v):
    for i in xrange(2, int(sqrt(v) + 1)):
        if v % i == 0:
            return False
    return True

for i in xrange(9, 0, -1):
    r = map(str, range(1, i + 1))
    for p in permutations(r):
        v = int(''.join(p))
        if is_prime(v):
            ans = max(ans, v)

print ans