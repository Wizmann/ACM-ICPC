#!/usr/bin/python

n = int(raw_input())

d = {}

for i in xrange(n):
    s = raw_input()
    d[s] = d.get(s, 0) + 1

q = int(raw_input())

for i in xrange(q):
    s = raw_input()
    print d.get(s, 0)