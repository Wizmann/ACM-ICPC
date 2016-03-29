#!/usr/bin/python
import sys

(h1, h2) = map(int, raw_input().split())
(a, b) = map(int, raw_input().split())

MAXI = 10 ** 5

for i in xrange(0, MAXI):
    h = 12 * (a - b) * i + 8 * a
    if h1 + h >= h2:
        print i
        break
else:
    print -1
