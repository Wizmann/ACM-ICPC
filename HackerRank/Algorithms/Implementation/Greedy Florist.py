#!/bin/python

import sys

def getMinimumCost(n, k, c):
    c.sort(reverse=True)
    res = 0
    for i in xrange(k):
        j = 0
        while i + j * k < n:
            res += (j + 1) * c[i + j * k]
            j += 1
    return res

n, k = raw_input().strip().split(' ')
n, k = [int(n), int(k)]
c = map(int, raw_input().strip().split(' '))
minimumCost = getMinimumCost(n, k, c)
print(minimumCost)
