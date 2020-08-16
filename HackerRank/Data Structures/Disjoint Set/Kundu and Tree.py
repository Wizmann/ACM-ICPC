import sys
from collections import defaultdict

sys.setrecursionlimit(123456)

MOD = (10 ** 9) + 7

class DisjointSet(object):
    def __init__(self, n):
        self.n = n
        self.father = range(n)

    def find_father(self, x):
        if self.father[x] == x:
            return x
        f = self.find_father(self.father[x])
        self.father[x] = f
        return f

    def make_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        self.father[fa] = fb

def C(n, m):
    res = 1
    for i in xrange(m):
        res *= n - i
        res *= pow(i + 1, MOD - 2, MOD)
    return res % MOD

n = int(raw_input())
ds = DisjointSet(n + 1)
for i in xrange(n - 1):
    a, b, c = raw_input().split()
    a = int(a)
    b = int(b)
    if c == 'b':
        ds.make_union(a, b)

tot = C(n, 3)
# print tot
d = defaultdict(int)

for i in xrange(1, n + 1):
    f = ds.find_father(i)
    d[f] += 1

for key, value in d.items():
    tot -= C(value, 3)
    tot = ((tot % MOD) + MOD) % MOD

for key, value in d.items():
    tot -= C(value, 2) * (n - value) % MOD
    tot = ((tot % MOD) + MOD) % MOD
print tot % MOD
