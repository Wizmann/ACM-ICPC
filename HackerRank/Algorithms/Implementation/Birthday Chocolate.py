#!/bin/python

import sys

def solve(n, s, d, m):
    cnt = 0
    for i in xrange(n - m + 1):
        u = sum(s[i: i + m])
        if u == d:
            cnt += 1
    return cnt

n = int(raw_input().strip())
s = map(int, raw_input().strip().split(' '))
d, m = raw_input().strip().split(' ')
d, m = [int(d), int(m)]
result = solve(n, s, d, m)
print(result)
