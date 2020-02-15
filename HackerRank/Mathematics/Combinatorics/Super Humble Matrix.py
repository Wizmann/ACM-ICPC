#!/bin/python3

# https://www.hackerrank.com/challenges/super-humble-matrix/problem

import os
import sys

MOD = (10 ** 9) + 7

fac = [1]
for i in range(1, 1234567):
    fac.append(fac[-1] * i % MOD)

# Complete the solve function below.
def solve(n, m):
    res = 1
    for i in range(1, n + m):
        res *= fac[min(n, m, i, n + m - i)]
        res %= MOD
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    result = solve(n, m)

    fptr.write(str(result) + '\n')

    fptr.close()
