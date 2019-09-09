#!/bin/python

from __future__ import print_function

import os
import sys

# Complete the solve function below.
def solve(n, m):
    tot = 0
    u = n / m
    tot += (m - 1) * m / 2 * u
    v = n % m
    tot += (v + 1) * v / 2
    return tot

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input())

    for t_itr in xrange(t):
        nm = raw_input().split()

        n = int(nm[0])

        m = int(nm[1])

        result = solve(n, m)

        fptr.write(str(result) + '\n')

    fptr.close()
