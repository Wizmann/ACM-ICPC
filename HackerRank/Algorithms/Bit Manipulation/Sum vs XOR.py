#!/bin/python

import sys


n = long(raw_input().strip())

m = n
while (m + 1) & m != 0:
    m |= (m >> 1)
print 1 << '{:b}'.format(m ^ n).count('1')
