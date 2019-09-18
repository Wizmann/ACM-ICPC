#!/bin/python

import os
import sys

MOD = (10 ** 9) + 7

# Complete the solve function below.
def solve(n):
    a = pow(2, n, MOD)
    b = ((a - 1) * 2 % MOD + MOD + 4) % MOD
    return b

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input())

    for t_itr in xrange(t):
        n = int(raw_input())

        result = solve(n)

        fptr.write(str(result) + '\n')

    fptr.close()
