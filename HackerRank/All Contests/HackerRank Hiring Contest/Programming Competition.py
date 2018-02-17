#!/bin/python

import sys

if __name__ == "__main__":
    n = int(raw_input().strip())
    ns = []
    for a0 in xrange(n):
        name, d, j = raw_input().strip().split(' ')
        name, d, j = [str(name), int(d), int(j)]
        
        ns.append((j - d, n - a0, name))
        
    res = max(ns)
    print res[2], res[0]
