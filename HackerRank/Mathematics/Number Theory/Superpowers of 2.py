#!/bin/python

import os
import sys

d = {}

# Complete the solve function below.
def solve(a, b):
    if a == 0:
        return 0
    u = 2
    for i in xrange(a):
        u = u * u % b
    return u

assert solve(0, 2) == 0

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ab = raw_input().split()

    a = int(ab[0])

    b = int(ab[1])

    result = solve(a, b)

    fptr.write(str(result) + '\n')

    fptr.close()
