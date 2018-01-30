#!/bin/python

import sys

def canConstruct(a):
    return 'Yes' if sum(a) % 3 == 0 else 'No'

if __name__ == "__main__":
    t = int(raw_input().strip())
    for a0 in xrange(t):
        n = int(raw_input().strip())
        a = map(int, raw_input().strip().split(' '))
        result = canConstruct(a)
        print result

