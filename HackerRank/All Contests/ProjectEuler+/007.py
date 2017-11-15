#!/bin/python

import sys

N = 123456
sieve = [False for i in xrange(N)]

for i in xrange(2, N):
    j = 2
    if sieve[i]:
        continue
    while i * j < N:
        sieve[i * j] = True
        j += 1
        
primes = []
for i in xrange(2, N):
    if not sieve[i]:
        primes.append(i)

t = int(raw_input().strip())
for a0 in xrange(t):
    n = int(raw_input().strip())
    print primes[n - 1]
