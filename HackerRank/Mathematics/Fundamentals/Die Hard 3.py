#!/bin/python

from __future__ import print_function

import os
import sys

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def solve(a, b, c):
    return "YES" if c <= max(a, b) and c % gcd(a, b) == 0 else "NO"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input())

    for t_itr in xrange(t):
        abc = raw_input().split()

        a = int(abc[0])

        b = int(abc[1])

        c = int(abc[2])

        result = solve(a, b, c)

        fptr.write(result + '\n')

    fptr.close()
