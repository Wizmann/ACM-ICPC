#!/bin/python

from __future__ import print_function

import os
import sys
from collections import defaultdict

# Complete the solve function below.
def solve(dates):
    d = defaultdict(list)
    for (mm, dd) in dates:
        try:
            v = int(str(dd), mm)
            d[v].append((mm, dd))
        except:
            continue
    #print(d)
    res = 0
    for (key, value) in d.items():
        if value:
            l = len(value)
            res += l * (l - 1) / 2
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(raw_input())

    dates = []

    for _ in xrange(n):
        dates.append(map(int, raw_input().rstrip().split()))

    result = solve(dates)

    fptr.write(str(result) + '\n')

    fptr.close()
