#!/bin/python

import os
import sys

d = {}

# Complete the solve function below.
def solve(n, m):
    if n == 0:
        return 0
    elif n == 1:
        return 1

    if n in d:
        return d[n]
    
    l = n / 2
    r = n - l

    res = 0
    res += solve(l, m) * pow(10, r, m) % m
    res += solve(r, m) % m
    res %= m
    d[n] = res
    return res



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input())

    for t_itr in xrange(t):
        d = {}
        nm = raw_input().split()

        n = int(nm[0])

        m = int(nm[1])

        result = solve(n, m)

        fptr.write(str(result) + '\n')

    fptr.close()
