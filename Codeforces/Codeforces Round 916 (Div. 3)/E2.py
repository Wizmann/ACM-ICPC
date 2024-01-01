#coding=utf-8

import sys
if sys.version_info[0] == 3:
    raw_input = input
    xrange = range
    map_ = map
    def map(*args, **kwargs):
        return list(map_(*args, **kwargs))

T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    As = map(int, raw_input().split())
    Bs = map(int, raw_input().split())

    S = []
    for i in xrange(n):
        S.append((As[i] + Bs[i] - 1, As[i], Bs[i]))
    S.sort(reverse=True)
    score = sum(As) - sum(Bs)
    # print(S)
    # print(score)
    for i, (s, a, b) in enumerate(S):
        if i % 2 == 0:
            score = score - 1 + b
        else:
            score = score + 1 - a
        # print(i, score)
    print(score)

'''
^^^^^TEST^^^^^
1
3
4 2 1
1 2 4
-----------
1
$$$TEST$$$$

^^^^^TEST^^^^^
5
3
4 2 1
1 2 4
4
1 20 1 20
100 15 10 20
5
1000000000 1000000000 1000000000 1000000000 1000000000
1 1 1 1 1
3
5 6 5
2 1 7
6
3 2 4 2 5 5
9 4 7 9 2 5
-------------
1
-9
2999999997
8
-6
$$$$TEST$$$$$
'''



