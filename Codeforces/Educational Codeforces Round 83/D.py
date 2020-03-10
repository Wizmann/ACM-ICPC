# https://codeforces.com/contest/1312/problem/D

MOD = 998244353
 
def C(m, n):
    res = 1
    for i in xrange(n):
        res = (res * (m - i)) % MOD
        res = (res * pow(i + 1, MOD - 2, MOD)) % MOD
    return res % MOD
 
assert C(5, 3) == 10
 
def solve(n, m):
    if n == 2:
        return 0
    return C(m, n - 1) * (n - 2) % MOD * pow(2, n - 3, MOD) % MOD
 
assert solve(2, 4) == 0
'''
assert solve(3, 4) == 6
assert solve(3, 5) == 10
assert solve(42, 1337) == 806066790
assert solve(100000, 200000) == 707899035
assert solve(200000, 200000)
'''
 
(n, m) = map(int, raw_input().split())
print solve(n, m)
 
