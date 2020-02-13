#!/bin/python3

# https://www.hackerrank.com/challenges/picking-cards/problem

import os
import sys

MOD = (10 ** 9) + 7

# Complete the solve function below.
def solve(c):
    c.sort()
    n = len(c)
    
    res = 1

    l, r = 0, 0
    while l < n:
        while r < n and c[r] <= l:
            r += 1
        res *= r - l
        res %= MOD
        l += 1
    return res
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        c_count = int(input())

        c = list(map(int, input().rstrip().split()))

        result = solve(c)

        fptr.write(str(result) + '\n')

    fptr.close()
