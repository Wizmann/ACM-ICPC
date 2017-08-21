#!/bin/python

import sys


t = int(raw_input().strip())
for a0 in xrange(t):
    n = long(raw_input().strip())
    a, b = 1, 1
    ans = 0
    while a + b <= n:
        c = a + b
        if c % 2 == 0:
            ans += c
        a, b = b, c
    print ans
