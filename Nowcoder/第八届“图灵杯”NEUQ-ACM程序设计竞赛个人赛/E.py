#coding=utf-8
from math import sqrt

def solve(n, x):
    a, b = x - 1, n - x
    a, b = min(a, b), max(a, b)

    fi = (sqrt(5) + 1) / 2

    k = b - a
    # print fi, k
    return a == int(k * fi)

T = int(raw_input())

for case_ in xrange(T):
    (n, x) = map(int, raw_input().split())

    if solve(n, x):
        # second player wins
        print 'ma la se mi no.1!'
    else:
        # first player wins
        print 'yo xi no forever!'

'''
^^^TEST^^^
8
1 1
10 3
17 6
12 5
4 3
9 6
12 8
17 11
--------
ma la se mi no.1!
yo xi no forever!
yo xi no forever!
ma la se mi no.1!
ma la se mi no.1!
ma la se mi no.1!
ma la se mi no.1!
ma la se mi no.1!
$$$TEST$$$
'''
