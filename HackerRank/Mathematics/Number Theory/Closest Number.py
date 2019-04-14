#!/bin/python

from __future__ import print_function

import os
import sys

#
# Complete the closestNumber function below.
#
def closestNumber(a, b, x):
    a = int(a ** b)
    c = a / x
    r1 = c * x
    r2 = (c + 1) * x
    if abs(r1 - a) <= abs(r2 - a):
        return r1
    else:
        return r2

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input())

    for t_itr in xrange(t):
        abx = raw_input().split()

        a = int(abx[0])

        b = int(abx[1])

        x = int(abx[2])

        result = closestNumber(a, b, x)

        fptr.write(str(result) + '\n')

    fptr.close()
