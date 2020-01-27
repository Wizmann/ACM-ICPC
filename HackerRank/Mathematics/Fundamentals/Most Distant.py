#!/bin/python

from __future__ import print_function

import os
import sys
from math import sqrt

INF = 10 ** 10

# Complete the solve function below.
def solve(coordinates):
    maxx, minx = -INF, INF
    maxy, miny = -INF, INF
    for (y, x) in coordinates:
        if y == 0:
            maxx = max(maxx, x)
            minx = min(minx, x)
        if x == 0:
            maxy = max(maxy, y)
            miny = min(miny, y)
    res = max(
        maxx - minx,
        maxy - miny,
        sqrt(maxx ** 2 + maxy ** 2),
        sqrt(maxx ** 2 + miny ** 2),
        sqrt(minx ** 2 + maxy ** 2),
        sqrt(minx ** 2 + miny ** 2)
    )
    return '%.6f' % res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(raw_input())

    coordinates = []

    for _ in xrange(n):
        coordinates.append(map(int, raw_input().rstrip().split()))

    result = solve(coordinates)

    fptr.write(str(result) + '\n')

    fptr.close()
