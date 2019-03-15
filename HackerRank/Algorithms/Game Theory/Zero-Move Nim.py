#!/bin/python

from __future__ import print_function

import os
import sys

def SG(x):
    if x % 2 == 1:
        return x + 1
    else:
        return x - 1

def zeroMoveNim(p):
    return "W" if reduce(lambda x, y: x ^ y, map(SG, p)) else "L"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    g = int(raw_input())

    for g_itr in xrange(g):
        n = int(raw_input())

        p = map(int, raw_input().rstrip().split())

        result = zeroMoveNim(p)

        fptr.write(result + '\n')

    fptr.close()
