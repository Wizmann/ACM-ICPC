#pypy
#coding=utf-8

INF = 10 ** 10
MOD = 998244353
BIT = 14

N = 5555
factorials = [0 for i in xrange(N)]
factorials[0] = 1
for i in xrange(1, N):
    factorials[i] = factorials[i - 1] * i % MOD
invs = [0 for i in xrange(N)]
for i in xrange(N):
    invs[i] = pow(factorials[i], MOD - 2, MOD)

def C(n, m):
    if n == 0:
        return 1
    a = factorials[n] * invs[n - m] % MOD
    b = invs[m]
    return a * b % MOD

n, m = map(int, raw_input().split())

c = [0 for i in xrange(n + 1)]
for i in xrange(0, n + 1, 2):
    c[i] = C(n, i)

dp = [ {}, {} ]
dp[0][0] = 1
p = 0
for i in xrange(BIT):
    q = p ^ 1
    cur = 1 if m & (1 << i) else 0
    dp[q] = {}
    # print len(dp[p])
    for (key, value) in dp[p].items():
        for j in xrange(0, n + 1, 2):
            if (1 << i) * j > m:
                break
            u = key + j
            if u % 2 != cur:
                continue
            dp[q][u / 2] = (dp[q].get(u / 2, 0) + c[j] * value) % MOD
    # print dp[q]
    p = q
print dp[p].get(0, 0) % MOD

'''

^^^TEST^^^
5 20
-----
475
$$$TEST$$$

^^^TEST^^^
10 5
-----
0
$$$TEST$$$

^^^TEST^^^^
3141 2718
----
371899128
$$$TEST$$$

'''



