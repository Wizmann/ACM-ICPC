#!/bin/python

import sys


s = raw_input().strip()

scores = set()

score = 0
pre = ''
for c in s:
    if c != pre:
        score = 0
        pre = ''
    
    score = score + ord(c) - ord('a') + 1
    pre = c
    scores.add(score)

n = int(raw_input().strip())
for a0 in xrange(n):
    x = int(raw_input().strip())
    print 'Yes' if x in scores else 'No'
