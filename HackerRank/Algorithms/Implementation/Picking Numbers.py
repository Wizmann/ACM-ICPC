#!/bin/python

import sys
from collections import Counter

n = int(raw_input().strip())
a = map(int,raw_input().strip().split(' '))

c = Counter(a)

ans = 0
for (key, value) in c.items():
    ans = max(ans, value + c[key + 1])
print ans
