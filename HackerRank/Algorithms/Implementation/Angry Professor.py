#!/bin/python

import sys


t = int(raw_input().strip())
for a0 in xrange(t):
    n,k = raw_input().strip().split(' ')
    n,k = [int(n),int(k)]
    a = map(int,raw_input().strip().split(' '))
    if len(filter(lambda x: x <= 0, a)) >= k:
        print 'NO'
    else:
        print 'YES'
