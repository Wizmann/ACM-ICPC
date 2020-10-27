#coding=utf-8

from collections import Counter

(n, m) = map(int, raw_input().split())

ns = map(int, raw_input().split())

c = Counter(ns)

if c[1] >= 2:
    print 2
else:
    print 3

'''
^^^TEST^^^
5 3
1 1 2 2 3
----
2
$$$TEST$$$

^^^TEST^^^
5 3
1 5 2 2 3
----
3
$$$TEST$$$
'''
