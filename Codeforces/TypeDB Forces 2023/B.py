from collections import defaultdict

T = int(raw_input())

MAX_PRIME = 123456

sieve = [1 for i in xrange(MAX_PRIME)]
sieve[2] = 1
for i in xrange(3, MAX_PRIME, 2):
    j = 2
    while i * j < MAX_PRIME:
        sieve[i * j] = 0
        j += 1

primes = []
for i in xrange(2, MAX_PRIME):
    if sieve[i]:
        primes.append(i)

for case_ in xrange(T):
    n = int(raw_input())

    d = defaultdict(int)

    for prime in primes:
        while n % prime == 0:
            d[prime] += 1
            n /= prime
    if n > 1:
        d[n] += 1

    tot = 0
    while d:
        cur = 1
        for key, value in d.items():
            cur *= key
            d[key] -= 1
            if d[key] == 0:
                del d[key]
        if cur > 1:
            tot += cur
    print tot

'''
^^^^TEST^^^^^
7
100
10
864
130056192
1000000000
2
999999018
----------------
20
10
22
118
90
2
333333009
$$$$$TEST$$$$
'''
