#!/bin/python

import sys
from collections import Counter

def isValid(s):
    c = Counter(map(lambda x: x[1], Counter(s).items()))
    if len(c) == 1:
        return True
    elif len(c) == 2:
        mini = min(c.items(), key=lambda (w, c): w)[0]
        return c[mini + 1] == 1 or c[1] == 1
    else:
        return False
        
s = raw_input().strip()
result = isValid(s)
print('YES' if result else 'NO')
