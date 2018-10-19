#!/bin/python

import math
import os
import random
import re
import sys

INF = 10 ** 10
result = []

def kFactorization(n, A, st):
    global result
    if n == 1:
        if not result or len(st) < len(result):
            result = st[:]
        elif len(st) == len(result):
            result = min(result, st)[:]
        return
    for i, a in enumerate(A):
        if n % a == 0:
            st.append(a)
            kFactorization(n / a, A[i:], st)   
            st.pop()
       

if __name__ == '__main__':
    fptr = sys.stdout

    nk = raw_input().split()

    n = int(nk[0])

    k = int(nk[1])

    A = sorted(map(int, raw_input().rstrip().split()))

    st = []
    kFactorization(n, A, st)
    if result:
        m = len(result)
        cur = 1
        result.append(0)
        for i in xrange(0, m + 1):
            result[i], cur = cur, cur * result[i]
        fptr.write(' '.join(map(str, result)))
        fptr.write('\n')
    else:
        fptr.write('-1\n')

    fptr.close()

