#python3
#coding=utf-8

import sys
from collections import defaultdict

if sys.version_info[0] == 3:
    raw_input = input
    xrange = range
    map_ = map
    def map(*args, **kwargs):
        return list(map_(*args, **kwargs))

N = 123
dp = [ [0 for i in xrange(N)] for j in xrange(N) ]
n = int(raw_input())
dp[0][0] = 1

for i in xrange(1, n + 1):  # push
    for j in xrange(i + 1): # pop
        if i - 1 >= j:
            dp[i][j] += dp[i - 1][j]
        dp[i][j] += dp[i][j - 1]

print(dp[n][n])

'''
^^^TEST^^^^
3
----------
5
$$$TEST$$$
'''
