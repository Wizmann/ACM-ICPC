import sys
from collections import defaultdict
 
MOD = (10 ** 9) + 7
 
n, m = map(int, raw_input().split())
 
d = {}
def solve(space, take):
    key = (space, take)
    if space == 0 and take > 0:
        return 0
    if space == 0:
        return 1
    if take == 0:
        return 1
    if key in d:
        return d[key]
    res = 0
    res += solve(space, take - 1) % MOD
    res += solve(space - 1, take) % MOD
    res %= MOD
    d[key] = res
    return res
 
assert solve(1, 1) == 1
assert solve(2, 1) == 2
assert solve(1, 2) == 1
 
res = 0
for i in xrange(1, n + 1):
    for j in xrange(i, n + 1):
        l = i
        r = n - j + 1
        ll = solve(l, m) - solve(l - 1, m)
        rr = solve(r, m) - solve(r - 1, m)
        #print l, r, ll, rr
        res += ll * rr % MOD
        res %= MOD
print res
