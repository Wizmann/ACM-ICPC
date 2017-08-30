#!/bin/python

import sys
from collections import Counter

def migratoryBirds(n, ar):
    c = Counter(ar)
    return sorted(c.items(), key=lambda x: x[1], reverse=True)[0][0]

n = int(raw_input().strip())
ar = map(int, raw_input().strip().split(' '))
result = migratoryBirds(n, ar)
print(result)
