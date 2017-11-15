#!/bin/python

import sys


t = int(raw_input().strip())
for a0 in xrange(t):
    n,k = raw_input().strip().split(' ')
    n,k = [int(n),int(k)]
    num = raw_input().strip()
    ans = 0
    for i in xrange(k, n + 1):
        u = reduce(lambda x, y: x * y, map(int, num[i - k: i]))
        ans = max(ans, u)
    print ans

