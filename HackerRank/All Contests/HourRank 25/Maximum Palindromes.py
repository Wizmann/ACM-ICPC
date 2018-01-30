#!/bin/python

import sys
import string

ALPHA = 30
N = 123456
MOD = (10 ** 9) + 7

prefix = []
factor = [0 for i in xrange(N)]
rev_factor = [0 for i in xrange(N)]
prefix = [ [0 for i in xrange(N)] for j in xrange(ALPHA) ]

def alpha_to_int(c):
    return ord(c) - ord('a')

def initialize(s):
    n = len(s)

    for i in xrange(n):
        for j in xrange(ALPHA):
            if i - 1 >= 0:
                prefix[j][i] += prefix[j][i - 1]
        c = alpha_to_int(s[i])
        prefix[c][i] += 1    
    
    factor[0] = 1
    rev_factor[0] = 1
    for i in xrange(1, N):
        factor[i] = (factor[i - 1] * i) % MOD
        rev_factor[i] = pow(factor[i], MOD - 2, MOD)

def answerQuery(l, r):
    r -= 1
    l -= 1
    
    odds, evens = [], []
    
    for i in xrange(ALPHA):
        diff = prefix[i][r] - (0 if l - 1 < 0 else prefix[i][l - 1])
        if diff and diff % 2 == 0:
            evens.append(diff)
        elif diff and diff % 2 == 1:
            odds.append(diff)
    
    res = 1
    m = 0
    #print m, evens, odds
    for diff in evens:
        res = (res * rev_factor[diff / 2]) % MOD
        m += diff / 2

    for diff in odds:
        res = (res * rev_factor[diff / 2]) % MOD
        m += diff / 2

    res = (res * factor[m]) % MOD
    if odds:
        res *= len(odds)
        
    return res % MOD
    
if __name__ == "__main__":
    s = raw_input().strip()
    initialize(s)
    q = int(raw_input().strip())
    for a0 in xrange(q):
        l, r = raw_input().strip().split(' ')
        l, r = [int(l), int(r)]
        result = answerQuery(l, r)
        print result


