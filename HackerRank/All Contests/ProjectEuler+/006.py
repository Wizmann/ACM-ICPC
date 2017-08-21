#!/bin/python

import sys


t = int(raw_input().strip())
for a0 in xrange(t):
    n = int(raw_input().strip())
    print (sum(range(n + 1)) ** 2) - sum(map(lambda x: x ** 2, range(n + 1)))
