#coding=utf-8

import sys

T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())

    for i in xrange(1, n):
        delta = min(ns[i], ns[i - 1])
        ns[i - 1] -= delta
        ns[i] -= delta

    if sorted(ns) == ns:
        print 'YES'
    else:
        print 'NO'


'''
^^^^TEST^^^
5
5
1 2 3 4 5
4
4 3 2 1
4
4 5 2 3
8
4 5 4 5 4 5 4 5
9
9 9 8 2 4 4 3 5 3
----------------
YES
NO
YES
YES
NO
$$$$$$$TEST$$$$

'''
