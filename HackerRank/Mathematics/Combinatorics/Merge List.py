# https://www.hackerrank.com/challenges/merge-list/problem

#!/bin/python3

import os
import sys

MOD = (10 ** 9) + 7

def C(n, m):
    print(n, m)
    tot = 1
    for i in range(m):
        tot = tot * (n - i) % MOD
    for i in range(1, m + 1):
        tot = tot * pow(i, MOD - 2, MOD) % MOD
    return tot        

# Complete the solve function below.
def solve(n, m):
    return C(n + m, n)

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
