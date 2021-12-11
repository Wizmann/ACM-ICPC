#coding=utf-8
import sys

from collections import defaultdict

def dfs(dp, n, k):
    if n == 0:
        return True
    if n == 1:
        return False
    if n in dp:
        return dp[n]
    
    flag = False
    for i in xrange(1, k + 1):
        if n - i < 0:
            continue
        if not dfs(dp, n - i, k):
            flag = True
            break

    dp[n] = flag
    return flag

'''
d = defaultdict(list)

for i in xrange(1, 100):
    for j in xrange(1, i + 1):
        dp = {}
        res = dfs(dp, i, j)
        if not res:
            d[j].append(i)

for key, value in d.items():
    print key, value
'''

T = int(raw_input())

for case_ in xrange(T):
    n, k = map(int, raw_input().split())
    k = min(n, k)

    m = n - (k + 2)
    # print n, k, m
    if (n == 1 and k == 1) or m % (k + 1) == 0:
        res = False
    else:
        res = True

    if res:
        sys.stdout.write("yo xi no forever!")
    else:
        sys.stdout.write("ma la se mi no.1!")
    if case_ != T - 1:
        sys.stdout.write("\n")

'''
^^^^TEST^^^
4
1 1
23 2
6 4
114 514
---------
ma la se mi no.1!
yo xi no forever!
ma la se mi no.1!
yo xi no forever!
$$$TEST$$$
'''



