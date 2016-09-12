#!/bin/python

As = map(int, raw_input().split())
Bs = map(int, raw_input().split())
n = len(As)

assert len(As) == len(Bs)

sa, sb = 0, 0
for i in xrange(n):
    if As[i] > Bs[i]:
        sa += 1
    elif As[i] < Bs[i]:
        sb += 1
print sa, sb
