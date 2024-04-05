#coding=utf-8

INF = 10 ** 10

(n, c) = map(int, raw_input().split())
c -= 1
tot = 0

lights = []
for i in xrange(n):
    (p, w) = map(int, raw_input().split())
    lights.append((p, w))
    tot += w

dp = [ [INF for i in xrange(n)] for j in xrange(n) ]

def dfs(p, q, totw):
    if dp[p][q] < INF:
        return dp[p][q]

    if min(p, q) == 0 and max(p, q) == n - 1:
        return 0

    totw -= lights[p][1]

    cur = INF
    l, r = min(p, q) - 1, max(p, q) + 1
    if l >= 0:
        dis = abs(lights[p][0] - lights[l][0])
        cur = min(cur, dis * totw + dfs(l, max(p, q), totw))
    if r < n:
        dis = abs(lights[p][0] - lights[r][0])
        cur = min(cur, dis * totw + dfs(r, min(p, q), totw))
    dp[p][q] = cur
    return cur

print dfs(c, c, tot)

'''
^^^TEST^^^
5 3
2 10
3 20
5 20
6 30
8 10
---
270
$$$TEST$$$
'''

