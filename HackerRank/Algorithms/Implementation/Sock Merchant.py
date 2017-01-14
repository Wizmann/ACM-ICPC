#!/bin/python

import sys


n = int(raw_input().strip())
c = map(int,raw_input().strip().split(' '))

d = {}

for item in c:
    d[item] = d.get(item, 0) + 1

ans = 0
for key, value in d.items():
    ans += value / 2
print ans
