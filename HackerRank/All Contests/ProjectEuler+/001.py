#!/bin/python

import sys


t = int(raw_input().strip())
for a0 in xrange(t):
    n = int(raw_input().strip()) - 1
     
    res = 0
    res += (1 + n / 3) * (n / 3) / 2 * 3 
    res += (1 + n / 5) * (n / 5) / 2 * 5
    res -= (1 + n / 15) * (n / 15) / 2 * 15
    print res
