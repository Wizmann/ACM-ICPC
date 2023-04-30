#coding=utf-8

from collections import defaultdict

def solve(ns, n, k):
    d = defaultdict(list)

    for i, num in enumerate(ns):
        d[num % k].append(i + 1)

    cnt = 0
    for key, vs in d.items():
        if key == 0:
            key = k
        m = len(vs)
        vs.sort()

        target = []
        for i in xrange(m):
            target.append(key + k * i)
        # print vs, target
        cnt += m - len(set(vs) & set(target))

    # print '>', cnt
    if cnt == 0:
        return 0
    elif cnt == 2:
        return 1
    else:
        return -1


T = int(raw_input())

for case_ in xrange(T):
    n, k = map(int, raw_input().split())
    ns = map(int, raw_input().split())

    print solve(ns, n, k)

'''
^^^^^TEST^^^^
6
4 1
3 1 2 4
4 2
3 4 1 2
4 2
3 1 4 2
10 3
4 5 9 1 8 6 10 2 3 7
10 3
4 6 9 1 8 5 10 2 3 7
10 3
4 6 9 1 8 5 10 3 2 7
---------------
0
0
1
0
1
-1
$$$TEST$$$
'''

