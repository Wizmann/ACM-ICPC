#!/bin/python

from __future__ import print_function

import os
import sys

d = {}

def mex(nums):
    cur = 0
    while cur in nums:
        cur += 1
    return cur

def grundy(c):
    if c <= 0:
        return 0
    
    if c in d:
        return d[c]
    
    if c in [1, 2]:
        d[c] = c
    else:
        st = set()
        for i in xrange(c):
            a = grundy(i) ^ grundy(c - i - 1)
            b = grundy(i) ^ grundy(c - i - 2)
            
            st.add(a)
            st.add(b)
            
        d[c] = mex(st)
    return d[c]    

def isWinning(n, config):
    config = map(lambda y: grundy(len(y)), filter(lambda x: x, config.strip().split('X')))
    flag = reduce(lambda x, y: x ^ y, config)
    return 'WIN' if flag else 'LOSE'

if __name__ == '__main__':
    sys.stdout = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input())

    for t_itr in xrange(t):
        n = int(raw_input())

        config = raw_input()

        result = isWinning(n, config)

        print(result)
