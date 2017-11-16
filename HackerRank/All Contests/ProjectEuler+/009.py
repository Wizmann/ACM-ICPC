#!/bin/python

import sys
import math

N = 2222

sq = set([i * i for i in xrange(1, N)])
d = {}

for i in xrange(1, N):
    for j in xrange(i, N):
        k = int(math.sqrt(i * i + j * j))
        if i * i + j * j != k * k:
            continue
        n = i + j + k
        d[n] = max(d.get(n, 0), i * j * k)

t = int(raw_input().strip())
for a0 in xrange(t):
    n = int(raw_input().strip())
    print d.get(n, -1)
