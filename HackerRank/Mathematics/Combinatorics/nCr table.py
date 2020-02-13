#!/bin/python3

# https://www.hackerrank.com/challenges/ncr-table/problem

import os
import sys

sys.setrecursionlimit(10 ** 6)

# Complete the solve function below.

MOD = 10 ** 9

# c(n-1,m-1)+c(n-1,m)

d = {}

def C(n, m):
    if m == 0:
        return 1
    if n == m:
        return 1
    key = (n, m)
    if key in d:
        return d[key]
    res = (C(n - 1, m - 1) + C(n - 1, m)) % MOD
    d[key] = res
    return res    

def solve(n):
    for i in range(0, n + 1):
        yield C(n, i)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        result = solve(n)

        fptr.write(' '.join(map(str, result)))
        fptr.write('\n')

    fptr.close()
