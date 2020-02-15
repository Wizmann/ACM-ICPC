#!/bin/python3

# https://www.hackerrank.com/challenges/antipalindromic-strings/problem

import os
import sys

MOD = (10 ** 9) + 7

# Complete the solve function below.
def solve(n, m):
    if n == 1:
        return m
    return m * (m - 1) * (pow(m - 2, n - 2, MOD)) % MOD

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        nm = input().split()

        n = int(nm[0])

        m = int(nm[1])

        result = solve(n, m)

        fptr.write(str(result) + '\n')

    fptr.close()
