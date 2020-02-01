#!/bin/python

from __future__ import print_function

import os
import sys

MOD = 10 ** 9

# Complete the solve function below.

def C(a, b):
    res = 1
    for i in xrange(b):
        res *= (a - i)
        res /= i + 1
    return res % MOD

def solve(n, k):
    return C(n + k - 1, n - 1)
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input())

    for t_itr in xrange(t):
        n = int(raw_input())

        k = int(raw_input())

        result = solve(n, k)
        fptr.write(str(result) + '\n')

    fptr.close()
