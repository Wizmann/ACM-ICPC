#coding=utf-8
import sys
from collections import defaultdict

INF = 10 ** 10

def get_mex(d):
    i = 0
    while True:
        if not d[i]:
            return i
        i += 1
    assert False

def is_non_decreasing(ns):
    n = len(ns)
    for i in xrange(1, n):
        if ns[i] < ns[i - 1]:
            return False
    return True

T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())

    d = defaultdict(set)
    steps = []

    for i, num in enumerate(ns):
        d[num].add(i)

    for i in xrange(n):
        if is_non_decreasing(ns):
            break
        if ns[i] == i:
            continue

        while ns[i] != i:
            mex = get_mex(d)
            if mex == n:
                for j in xrange(i, n):
                    if ns[j] != j:
                        p = j
                        break
            else:
                p = mex
            d[ns[p]].remove(p)
            ns[p] = mex
            d[mex].add(p)
            steps.append(p)
        # print ns

    print len(steps)
    print ' '.join(map(str, map(lambda x: x + 1, steps)))
    assert len(steps) <= 2 * n
    # print ns
    assert is_non_decreasing(ns)

'''
^^^TEST^^^
5
3
2 2 3
3
2 1 0
7
0 7 3 1 3 7 7
9
2 0 1 1 2 4 4 2 0
9
8 4 7 6 1 2 3 0 5
-------
0

2
3 1
4
2 5 5 4
11
3 8 9 7 8 5 9 6 4 1 2
10
1 8 1 9 5 2 4 6 3 7
$$$TEST$$$
'''


