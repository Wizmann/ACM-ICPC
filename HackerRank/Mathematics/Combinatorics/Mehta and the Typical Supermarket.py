#!/bin/python3

# https://www.hackerrank.com/challenges/mehta-and-the-typical-supermarket/problem

import os
import sys

from collections import defaultdict

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

def do_solve(u, n, d):
    tot = 0
    for i in range(1, n + 1):
        for v in d[i]:
            if i % 2 == 0:
                tot -= u // v
            else:
                tot += u // v
    return tot

def solve(a, days):
    n = len(a)
    d = defaultdict(list)

    for i in range(1 << n):
        c = '{:b}'.format(i).count('1')
        u = 1
        for j in range(n):
            if i & (1 << j):
                u = lcm(u, a[j])
        d[c].append(u)

    for (l, r) in days:
        yield do_solve(r, n, d) - do_solve(l - 1, n, d)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a_count = int(input())

    a = []

    for _ in range(a_count):
        a_item = int(input())
        a.append(a_item)

    d = int(input())

    days = []

    for _ in range(d):
        days.append(list(map(int, input().rstrip().split())))

    result = solve(a, days)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
