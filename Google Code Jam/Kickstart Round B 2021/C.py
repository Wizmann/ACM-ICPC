import math

N = 33333
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

T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
 
    u = int(math.sqrt(n) + N)
    l = max(2, u - 10 * N)
    r = u

    # print l, r
    sieve = [True for i in xrange(r - l + 1)]

    for prime in primes:
        j = (l / prime)
        while prime * j < r:
            p = prime * j - l
            # print p, prime * j, l
            if p >= 0 and p < len(sieve) and j > 1:
                sieve[p] = False
            j += 1
    vs = []
    for i in xrange(r - l + 1):
        p = len(sieve) - i - 1
        if sieve[p]:
            vs.append(u - i)
    m = len(vs)
    ans = 0
    # print vs
    for i in xrange(m - 1):
        if vs[i] * vs[i + 1] <= n:
            # print vs[i], vs[i + 1]
            ans = vs[i] * vs[i + 1]
            break
    assert ans != 0 and ans <= n
    print 'Case #%d: %d' % (case_ + 1, ans)


'''
^^^TEST^^^
2
2021
2020
----
Case #1: 2021
Case #2: 1763
$$$TEST$$$

^^^TEST^^^
2
6
20
---
Case #1: 6
Case #2: 15
$$$TEST$$$

^^^TEST^^^
2
123456789012345678
123456789012345678
---
Case #1: 123456779959788731
Case #2: 123456779959788731
$$$TEST$$$


'''


