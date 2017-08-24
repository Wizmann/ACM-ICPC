#!/bin/python

import sys


q = int(raw_input().strip())
for a0 in xrange(q):
    x,y,z = raw_input().strip().split(' ')
    x,y,z = [int(x),int(y),int(z)]
    da, db = abs(x - z), abs(y - z)
    if da > db:
        print 'Cat B'
    elif da < db:
        print 'Cat A'
    else:
        print 'Mouse C'
