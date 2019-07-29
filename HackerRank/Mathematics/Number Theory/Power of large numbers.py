#!/bin/python

from __future__ import print_function

import os
import sys

# Complete the solve function below.
def solve(a, b):
    a, b = map(int, [a, b])
    MOD = (10 ** 9) + 7
    a %= MOD
    return pow(a, b, MOD)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input())

    for t_itr in xrange(t):
        ab = raw_input().split()

        a = ab[0]

        b = ab[1]

        result = solve(a, b)

        fptr.write(str(result) + '\n')

    fptr.close()
