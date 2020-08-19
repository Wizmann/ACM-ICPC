#!/bin/python

from __future__ import print_function

import os
import sys

from collections import defaultdict

sys.setrecursionlimit(123456)

class DisjointSet(object):
    def __init__(self, n):
        self.n = n
        self.father = range(n + 1)

    def find_father(self, x):
        if self.father[x] == x:
            return self.father[x]
        f = self.find_father(self.father[x])
        self.father[x] = f
        return f

def componentsInGraph(gb):
    ds = DisjointSet(len(gb) * 2)
    ps = set()
    for (a, b) in gb:
        fa = ds.find_father(a)
        fb = ds.find_father(b)
        ps.add(a)
        ps.add(b)

        ds.father[fb] = fa

    d = defaultdict(int)
    for i in ps:
        f = ds.find_father(i)
        d[f] += 1
    return min(d.values()), max(d.values())

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(raw_input())

    gb = []

    for _ in xrange(n):
        gb.append(map(int, raw_input().rstrip().split()))

    result = componentsInGraph(gb)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
