from math import sqrt
from itertools import permutations

def isPrime(x):
    upper = int(sqrt(x)) + 1
    for i in xrange(2, upper):
        if x % i == 0:
            return False
    return True

def main():
    d = {}
    ans = set()
    for i in xrange(1000, 10000):
        if isPrime(i):
            idx = tuple(sorted(str(i)))
            d[idx] = d.get(idx, []) + [i]
    for (key, value) in d.items():
        for term in permutations(value, 3):
            x, y, z = sorted(term)
            if x - y == y - z:
                ans.add(tuple([x, y, z]))
    print ans

main()

