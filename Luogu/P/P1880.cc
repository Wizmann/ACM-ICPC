#python3
#coding=utf-8

INF = 10 ** 10

import sys
if sys.version_info[0] == 3:
    raw_input = input
    xrange = range
    map_ = map
    def map(*args, **kwargs):
        return list(map_(*args, **kwargs))

n = int(raw_input())
ns = map(int, raw_input().split())
dp = {}

def dfs(l, r, ns, func):
    res = -1
    assert l != r
    if l + 1 == r:
        return 0
    if (l, r) in dp:
        return dp[(l, r)]

    for i in xrange(l + 1, r):
        a = dfs(l, i, ns, func)
        b = dfs(i, r, ns, func)
        if res == -1:
            res = a + b
        else:
            res = func(res, a + b)
    assert res != -1
    dp[(l, r)] = res + sum(ns[l: r])
    # print l, r, dp[(l, r)]
    return dp[(l, r)]

mini = INF
maxi = -INF

ns = ns + ns

dp = {}
for i in xrange(n):
    mini = min(mini, dfs(i, n + i, ns, min))

dp = {}
for i in xrange(n):
    maxi = max(maxi, dfs(i, n + i, ns, max))

print(mini)
print(maxi)

'''

^^^^^TEST^^^^^
1
1
-----------
0
0
$$$$$TEST$$$$

^^^^^TEST^^^^^
2
1 2
-----------
3
3
$$$$$TEST$$$$


^^^^^TEST^^^^^
3
1 2 3
-----------
9
11
$$$$$TEST$$$$

^^^^^TEST^^^^^
4
4 5 9 4
-----------
43
54
$$$$$TEST$$$$

^^^^^TEST^^^^^
78
4 4 10 13 7 1 16 7 0 7 19 7 9 14 18 1 5 17 1 8 11 19 15 18 11 12 2 3 7 1 13 0 17 10 2 5 1 7 1 10 7 0 12 10 9 10 9 18 11 11 7 8 6 10 7 18 1 11 2 3 18 9 17 17 10 14 16 1 4 7 1 5 11 3 13 17 7 0 
-----------
4084
28949
$$$$$TEST$$$$


'''
