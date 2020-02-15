#!/bin/python3

# https://www.hackerrank.com/challenges/number-list/problem

import os
import sys

# Complete the solve function below.
def solve(a, k):
    n = len(a)
    res = 0
    cnt = 0
    for i, num in enumerate(a + [k + 1]):
        if num > k:
            res += (1 + cnt) * cnt // 2
            cnt = 0
        else:
            cnt += 1

    return (1 + n) * n // 2 - res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        nk = input().split()

        n = int(nk[0])

        k = int(nk[1])

        a = list(map(int, input().rstrip().split()))

        result = solve(a, k)

        fptr.write(str(result) + '\n')

    fptr.close()
