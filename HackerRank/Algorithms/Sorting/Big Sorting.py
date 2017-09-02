#!/bin/python

import sys

def mycmp(x, y):
    if len(x) == len(y):
        return cmp(x, y)
    elif len(x) > len(y):
        return 1
    else:
        return -1

n = int(raw_input().strip())
unsorted = []
unsorted_i = 0
for unsorted_i in xrange(n):
    unsorted_t = str(raw_input().strip())
    unsorted.append(unsorted_t)
print '\n'.join(sorted(unsorted, cmp=mycmp))
