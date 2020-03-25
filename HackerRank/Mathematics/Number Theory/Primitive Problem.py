#!/bin/python

# https://www.hackerrank.com/challenges/primitive-problem/copy-from/149290507

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    p = int(raw_input())
    n = p - 1
    i = 2
    factors = []
    while i * i <= n:
        if n % i == 0:
            factors.append(i)
        while n % i == 0:
            n /= i
        i += 1
    if n > 1:
        factors.append(n)

    root = []
    for i in xrange(2, p):
        flag = True
        for f in factors:
            if pow(i, p / f, p) == 1:
                flag = False
                break
        if flag:
            print i,
            break
    p -= 1
    for f in factors:
        p = p / f * (f - 1)
    print p
    
