#!/bin/python

import sys


s = raw_input().strip()

ss = set()
l = len(s)
pre = None
cnt = 0

for i in xrange(l + 1):
    cur = s[i] if i < l else None
    if cur == pre:
        cnt += 1
    else:
        if pre:
            for j in xrange(1, cnt + 1):
                ss.add((ord(pre) - ord('a') + 1) * j)
        pre = cur
        cnt = 1
    

n = int(raw_input().strip())
for a0 in xrange(n):
    x = int(raw_input().strip())
    print 'Yes' if x in ss else 'No'
