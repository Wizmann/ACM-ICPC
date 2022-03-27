#coding=utf-8
import math
from math import sqrt

T = int(raw_input())

for case_ in xrange(T):
    (x, y) = map(int, raw_input().split())
    if x == 0 and y == 0:
        print 0
        continue

    c = int(sqrt(x * x + y * y))
    if c * c == x * x + y * y:
        print 1
    else:
        print 2

'''
^^^^TEST^^^
3
8 6
0 0
9 15
-------
1
0
2
$$$TEST$$$
'''




