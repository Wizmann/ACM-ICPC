#!/bin/python

import math
import os
import random
import re
import sys

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def solve(n, ns):
    if n == 1:
        return ns[0] + 1
    if n <= 2:
        return max(ns)
    dp1 = [0 for i in xrange(n)]
    dp2 = [0 for i in xrange(n)]

    dp1[0] = ns[0]
    for i in xrange(1, n):
        dp1[i] = gcd(dp1[i - 1], ns[i])
    dp1[-1] = ns[-1]
    for i in xrange(n - 2, -1, -1):
        dp2[i] = gcd(dp2[i + 1], ns[i])

    for i in xrange(n):
        u = -1
        if i - 1 >= 0:
            u = dp1[i - 1]
        if i + 1 < n:
            u = dp2[i + 1] if u == -1 else gcd(u, dp2[i + 1])
        # print ns[i], u
        if ns[i] % u != 0:
            return u
    return -1

if __name__ == '__main__':
    n = int(raw_input())
    ns = map(int, raw_input().rstrip().split())
    print solve(n, ns)
