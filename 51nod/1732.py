#!/usr/bin/python

n = int(raw_input())
dp = [[0 for i in xrange(n + 1)] for j in xrange(n + 1)]
s = raw_input()

for i in xrange(n - 1, -1, -1):
    for j in xrange(n - 1, -1, -1):
        if s[i] == s[j]:
            dp[i][j] = dp[i + 1][j + 1] + 1

q = int(raw_input())
for i in xrange(q):
    (a, b) = map(int, raw_input().split())
    print dp[a][b]