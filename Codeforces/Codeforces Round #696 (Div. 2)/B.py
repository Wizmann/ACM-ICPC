SIZE = 12345 * 2

sieve = [0 for i in xrange(SIZE)]

for i in xrange(2, SIZE):
    if sieve[i] == 1:
        continue
    j = 2
    while i * j < SIZE:
        sieve[i * j] = 1
        j += 1

primes = []

for k, v in enumerate(sieve):
    if v == 0:
        primes.append(k)
        
primes = primes[2:]

def next_prime(num):
    l = 0
    r = len(primes) - 1
    while l <= r:
        m = (l + r) >> 1
        if primes[m] < num:
            l = m + 1
        else:
            r = m - 1
    return primes[l]

T = int(raw_input())
for case_ in xrange(T):
    a = int(raw_input())
    u = next_prime(1 + a)
    v = next_prime(u + a)
    print u * v

'''
^^^TEST^^^
2
1
2
-----
6
15
$$$TEST$$$

^^^TEST^^^
4
381
165
79
2968
-----
294527
56279
13529
17632891
$$$TEST$$$
'''

