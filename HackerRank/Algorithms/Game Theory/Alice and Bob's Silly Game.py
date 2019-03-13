#!/bin/python

import os
import sys

N = 123456

primes = [2]

for i in xrange(3, N, 2):
    for prime in primes:
        if i % prime == 0:
            break
    else:
        primes.append(i)

#
# Complete the sillyGame function below.
#
def sillyGame(n):
    l, r = 0, len(primes)
    while l <= r:
        m = (l + r) >> 1
        if primes[m] > n:
            r = m - 1
        else:
            l = m + 1
    cnt = l
    return "Alice" if cnt % 2 == 1 else "Bob"
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    g = int(raw_input())

    for g_itr in xrange(g):
        n = int(raw_input())

        result = sillyGame(n)

        fptr.write(result + '\n')

    fptr.close()
