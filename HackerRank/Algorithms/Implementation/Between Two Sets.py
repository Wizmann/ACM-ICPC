#!/bin/python

import sys

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def lcm(a, b):
    return a * b / gcd(a, b)

def getTotalX(a, b):
    a = reduce(lcm, a, 1)
    cnt = 0
    k = 1
    while a * k <= min(b):
        if all(map(lambda x: x % (k * a) == 0, b)):
            cnt += 1
        k += 1
    return cnt

if __name__ == "__main__":
    n, m = raw_input().strip().split(' ')
    n, m = [int(n), int(m)]
    a = map(int, raw_input().strip().split(' '))
    b = map(int, raw_input().strip().split(' '))
    total = getTotalX(a, b)
    print total
