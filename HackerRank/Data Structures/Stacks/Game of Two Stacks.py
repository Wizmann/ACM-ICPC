#!/bin/python

from __future__ import print_function

import os
import sys

#
# Complete the twoStacks function below.
#
def twoStacks(x, a, b):
    n = len(a)
    m = len(b)

    p, q = 0, m
    psum, qsum = 0, sum(b)
    res = 0

    while p <= n:
        while q > 0 and psum + qsum > x:
            q -= 1
            qsum -= b[q]
        if psum + qsum > x:
            break
        res = max(res, p + q)
        if p < n:
            psum += a[p]
        p += 1
        
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    g = int(raw_input())

    for g_itr in xrange(g):
        nmx = raw_input().split()

        n = int(nmx[0])

        m = int(nmx[1])

        x = int(nmx[2])

        a = map(int, raw_input().rstrip().split())

        b = map(int, raw_input().rstrip().split())

        result = twoStacks(x, a, b)

        fptr.write(str(result) + '\n')

    fptr.close()

