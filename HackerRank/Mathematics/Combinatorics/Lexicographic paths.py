#!/bin/python3

# https://www.hackerrank.com/challenges/lexicographic-steps/problem

import os
import sys

d = [ [] for i in range(11) ]

for i in range(1 << 20):
    c = '{:b}'.format(i).count('1')
    if c <= 10:
        d[c].append(i)

def solve(x, y, k):
    z = x + y
    u = d[y][k]
    res = ''
    for i in range(z - 1, -1, -1):
        if u & (1 << i):
            res += 'V'
        else:
            res += 'H'
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        xyk = input().split()

        x = int(xyk[0])

        y = int(xyk[1])

        k = int(xyk[2])

        result = solve(x, y, k)

        fptr.write(result + '\n')

    fptr.close()
