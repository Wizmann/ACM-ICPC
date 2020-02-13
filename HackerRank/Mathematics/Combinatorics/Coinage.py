#!/bin/python3

# https://www.hackerrank.com/challenges/coinage/problem

import os
import sys

# Complete the solve function below.
def solve(n, coins):
    dp = [ [0 for i in range(n + 1)] for j in range(2) ]
    dp[0][0] = 1

    p, q = 0, 0
    for value, num in zip([1, 2, 5, 10], coins):
        q = p ^ 1
        dp[q] = dp[p][:]
        for i in range(1, num + 1):
            cur = i * value
            for j in range(n - cur, -1, -1):
                if dp[p][j] and j + cur <= n:
                    dp[q][j + cur] += dp[p][j]
        p = q
    return dp[p][n]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        coins = list(map(int, input().rstrip().split()))

        result = solve(n, coins)

        fptr.write(str(result) + '\n')

    fptr.close()
