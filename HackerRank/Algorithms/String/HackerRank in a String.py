#!/bin/python

import sys

q = int(raw_input().strip())
for a0 in xrange(q):
    s = list(raw_input().strip())
    t = list('hackerrank')
    
    
    while s and t:
        if s[-1] == t[-1]:
            t.pop()
        s.pop()
    if t:
        print 'NO'
    else:
        print 'YES'

