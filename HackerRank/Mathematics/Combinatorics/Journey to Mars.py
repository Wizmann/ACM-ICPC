#!/bin/python3

# https://www.hackerrank.com/challenges/ajourney/problem

import os
import sys
import math
from decimal import *

log2 = Decimal(2).log10()

# Complete the solve function below.
def solve(n, k):
    r = pow(2, n - 1, 10 ** k)
    n1 = (n - 1) * log2
    n1 = n1 - int(n1)
    n2 = pow(10, n1 + k - 1)
    l = int(n2)
    # print(l, r)
    return l + r

if __name__ == '__main__':
    fptr = sys.stdout

    t = int(input())

    for t_itr in range(t):
        nk = input().split()

        n = int(nk[0])

        k = int(nk[1])

        result = solve(n, k)

        fptr.write(str(result) + '\n')

    fptr.close()

