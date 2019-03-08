#!/bin/python

from __future__ import print_function

import os
import sys

#
# Complete the towerBreakers function below.
#

def countFactors(n):
    if n == 1:
        return 0
    i = 2
    cnt = 0
    while i * i <= n:
        while n % i == 0:
            cnt += 1
            n /= i
        i += 1
    if n != 1:
        cnt += 1
    return cnt

assert countFactors(2) == 1

def towerBreakers(arr):
    arr = map(countFactors, arr)
    return 1 if reduce(lambda x, y: x ^ y, arr) else 2


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input())

    for t_itr in xrange(t):
        arr_count = int(raw_input())

        arr = map(int, raw_input().rstrip().split())

        result = towerBreakers(arr)

        fptr.write(str(result) + '\n')

    fptr.close()
