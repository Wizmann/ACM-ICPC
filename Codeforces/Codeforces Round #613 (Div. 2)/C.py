from collections import defaultdict
 
INF = 10 ** 20
 
def solve(n):
    d = defaultdict(int)
 
    i = 2
    while i * i <= n:
        while n % i == 0:
            d[i] += 1
            n /= i
        if i == 2:
            i += 1
        else:
            i += 2
    if n != 1:
        d[n] += 1
 
    ns = []
    for key, value in d.items():
        ns.append(key ** value)
 
    n = len(ns)
    res = (INF, INF)
    for i in xrange(1 << n):
        l, r = 1, 1
        for j in xrange(n):
            if i & (1 << j):
                l *= ns[j]
            else:
                r *= ns[j]
        l, r = min(l, r), max(l, r)
        if max(l, r) < max(res):
            res = (l, r)
    return res
 
assert solve(2) == (1, 2)
assert solve(6) == (2, 3)
assert solve(4) == (1, 4)
assert solve(12) == (3, 4)
 
n = int(raw_input())
l, r = solve(n)
print l, r
 
