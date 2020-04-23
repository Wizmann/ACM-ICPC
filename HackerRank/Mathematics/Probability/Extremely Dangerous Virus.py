#!/bin/python

from __future__ import print_function

import os
import sys

MOD = (10 ** 9) + 7

# Complete the solve function below.
def solve(a, b, t):
    return pow((a + b) / 2, t, MOD)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    abt = raw_input().split()

    a = int(abt[0])

    b = int(abt[1])

    t = int(abt[2])

    result = solve(a, b, t)

    fptr.write(str(result) + '\n')

    fptr.close()
