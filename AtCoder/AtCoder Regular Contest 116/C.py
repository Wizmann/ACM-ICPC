#pypy
#coding=utf-8
from collections import defaultdict

INF = 10 ** 10
MOD = 998244353

N = 212345
sieve = [True for i in xrange(N)]

i = 2
while i * i < N:
    if sieve[i]:
        j = 2
        while i * j < N:
            sieve[i * j] = False
            j += 1
    i += 1

primes = []
for i in xrange(2, N):
    if sieve[i]:
        primes.append(i)

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


N, M = map(int, raw_input().split())
res = 0

for i in xrange(1, M + 1):
    cnt = 0
    d = defaultdict(int)
    cur = i
    for prime in primes:
        if prime * prime > cur:
            break
        while cur % prime == 0:
            d[prime] += 1
            cnt += 1
            cur /= prime
    if cur != 1:
        d[cur] += 1
    cur = 1
    for key, value in d.items():
        cur *= C(value + N - 1, N - 1)
        cur %= MOD
    # print '>>', i, cnt + N, N, cur
    res = (res + cur) % MOD

print res % MOD

'''
^^^TEST^^^
3 4
---
13
$$$TEST$$$

^^^TEST^^^
20 30
---
71166
$$$TEST$$$

^^^TEST^^^
200000 200000
----
835917264
$$$TEST$$$


'''
