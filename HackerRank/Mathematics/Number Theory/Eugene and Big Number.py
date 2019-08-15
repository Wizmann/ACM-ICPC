#!/bin/python

import os
import sys

d = {}

# Complete the solve function below.
def solve(a, n, m):
    if n == 0:
        return 0
    if n == 1:
        return a % m
    if n in d:
        return d[n]

    digits = len(str(a))
    l = n / 2
    r = n - l

    rl = solve(a, l, m) * pow(10, digits * r, m) % m
    rr = solve(a, r, m)

    r = (rl + rr) % m
    d[n] = r
    return r    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input())

    for t_itr in xrange(t):
        d = {}
        anm = raw_input().split()

        a = int(anm[0])

        n = int(anm[1])

        m = int(anm[2])

        result = solve(a, n, m)

        fptr.write(str(result) + '\n')

    fptr.close()
