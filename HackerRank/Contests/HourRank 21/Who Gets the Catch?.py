#!/bin/python

import sys

def whoGetsTheCatch(n, x, X, V):
    t = []
    for i in xrange(n):
        t.append((i, abs(X[i] - x) / V[i]))
    t = sorted(t, key=lambda entry: entry[1])
    if len(t) == 1:
        return t[0][0]
    elif t[0][1] == t[1][1]:
        return -1
    else:
        return t[0][0]
    

#  Return the index of the catcher who gets the catch, or -1 if no one gets the catch.
n, x = raw_input().strip().split(' ')
n, x = [int(n), int(x)]
X = map(int, raw_input().strip().split(' '))
V = map(int, raw_input().strip().split(' '))
result = whoGetsTheCatch(n, x, X, V)
print(result)
