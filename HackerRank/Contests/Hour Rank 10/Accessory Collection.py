#!/bin/python

import sys

def calc(L, A, N, D, k):
    if k == 0:
        return -1
    tail = N - (D - 1) * k - 1
    if tail < 0:
        return -1
    
    AA = A
    L -= tail
    s = tail * AA
    
    n = L / k
    m = L % k
    
    if n + (1 if m else 0) > A:
        return -1

    s += sum(range(AA - n + 1, AA + 1)) * k
    s += m * (AA - n)
    
    return s
    

T = int(raw_input().strip())
for a0 in xrange(T):
    L,A,N,D = raw_input().strip().split(' ')
    L,A,N,D = [int(L),int(A),int(N),int(D)]
    
    s = -1
    for i in xrange(1, L + 1):
        s = max(s, calc(L, A, N, D, i))
    if s < 0:
        print 'SAD'
    else:
        print s


