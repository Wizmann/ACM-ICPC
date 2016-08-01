#!/bin/python

import sys

def solve(x):
    res = 0
    if x == 1:
        return 0
    if x % 2 == 0:
        res = (x / 2) % 2
    x = (x + 1) / 2
    if x == 1:
        return res

    for i in xrange(1, 64):
        y = x % (1 << i)
        z = x / (1 << i)
        y = max(0, y - (1 << (i - 1)))
        ones = (z * (1 << (i - 1))) + y
        if ones % 2 == 1:
            res |= (1 << i)
    return res

assert solve(1) == 0
assert solve(2) == 1
assert solve(3) == 2
assert solve(4) == 2
assert solve(5) == 6

Q = int(raw_input().strip())
for a0 in xrange(Q):
    L,R = map(int, raw_input().strip().split(' '))
    print solve(R + 1) ^ solve(L)
