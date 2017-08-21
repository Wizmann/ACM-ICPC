#!/bin/python

import sys

def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

def lcm(a, b):
    return a * b / gcd(a, b)
    
t = int(raw_input().strip())
for a0 in xrange(t):
    n = int(raw_input().strip())
    print reduce(lambda x, y: lcm(x, y), range(1, n + 1), 1)
