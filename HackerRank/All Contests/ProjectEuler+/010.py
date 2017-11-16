#!/bin/python

import sys

N = 1234567
sieve = [False for i in xrange(N)]

for i in xrange(2, N):
    j = 2
    if sieve[i]:
        continue
    while i * j < N:
        sieve[i * j] = True
        j += 1
        
sieve[1] = 0 

for i in xrange(2, N):
    if sieve[i]:
        sieve[i] = sieve[i - 1]
    else:
        sieve[i] = sieve[i - 1] + i
        
t = int(raw_input().strip())
for a0 in xrange(t):
    n = int(raw_input().strip())
    print sieve[n]
