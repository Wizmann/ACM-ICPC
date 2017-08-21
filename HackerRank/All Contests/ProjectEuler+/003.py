#!/bin/python

import sys

primes = [2, 3]

for i in xrange(5, (10 ** 6) + 1, 2):
    flag = True
    for prime in primes:
        if prime * prime > i:
            break
        if i % prime == 0:
            flag = False
            break
        
    if flag:
        primes.append(i)
        
t = int(raw_input().strip())
for a0 in xrange(t):
    n = long(raw_input().strip())
    ans = 1
    for prime in primes:
        if n == 1:
            break
        if prime * prime > n:
            break
        while n % prime == 0:
            ans = prime
            n /= prime
    print max(ans, n)
