#!/bin/python3

# https://www.hackerrank.com/challenges/choose-and-calculate/problem

import os
import sys

MOD = (10 ** 9) + 7

d = {}

# Complete the solve function below.
def solve(balls, k):
    balls.sort()
    n = len(balls)

    b = 1
    for i in range(k - 1):
        b = b * pow(i + 1, MOD - 2, MOD) % MOD

    us = [0 for i in range(n)]
    a = 1
    for i in range(k - 1):
        a = (n - 1 - i) * a % MOD

    for i in range(n):
        assert(n - i - 1 >= 0)
        us[n - i - 1] = a * b % MOD
        a = a * pow(n - 1 - i, MOD - 2, MOD)
        a = a * (n - i - k) % MOD

    def C(n, m):
        if n < 0:
            return 0
        if m > n:
            return 0
        assert(m == k - 1)
        return us[n] % MOD

    res = 0
    for i, ball in enumerate(balls):
        res += ball * C(i, k - 1)
        res -= ball * C(n - i - 1, k - 1)
        res = ((res % MOD) + MOD) % MOD
    return res

assert(solve([10, 20, 30, 40], 1) == 0)
assert(solve([10, 20, 30, 40], 2) == 100)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    balls = list(map(int, input().rstrip().split()))

    result = solve(balls, k)

    fptr.write(str(result) + '\n')

    fptr.close()

