INF = 10 ** 10
(n, m) = map(int, raw_input().split())

prices = map(int, raw_input().split())

g = [ [] for i in xrange(n) ]
ind = [0 for i in xrange(n)]

for i in xrange(m):
    x, y = map(int, raw_input().split())
    x -= 1
    y -= 1
    ind[y] += 1
    assert x < y
    g[x].append(y)

dp = [INF for i in xrange(n)]
q = []
for i in xrange(n):
    if ind[i] == 0:
        q.append(i)

while q:
    nq = set([])
    for cur in q:
        for nxt in g[cur]:
            pp = min(dp[cur], prices[cur])
            if pp < dp[nxt]:
                dp[nxt] = pp
                nq.add(nxt)
    q = list(nq)

res = -INF
# print dp
for i in xrange(n):
    res = max(res, prices[i] - dp[i])
print res

'''
^^^TEST^^^
4 3
2 3 1 5
2 4
1 2
1 3
----
3
$$$TEST$$$

^^^TEST^^^
5 5
13 8 3 15 18
2 4
1 2
4 5
2 3
1 3
-----
10
$$$TEST$$$

^^^TEST^^^
3 1
1 100 1
2 3
----
-99
$$$TEST$$$
'''
