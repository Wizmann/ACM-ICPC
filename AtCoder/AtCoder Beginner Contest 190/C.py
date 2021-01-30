#coding=utf-8
INF = 10 ** 10

n, m = map(int, raw_input().split())

conds = []

for i in xrange(m):
    a, b = map(int, raw_input().split())
    conds.append((a, b))

k = int(raw_input())

ps = []

for i in xrange(k):
    a, b = map(int, raw_input().split())
    ps.append((a, b))

res = 0
for i in xrange(1 << k):
    ds = [ 0 for j in xrange(n + 1) ]
    for j in xrange(k):
        p = 0 if (i & (1 << j)) else 1
        ds[ps[j][p]] += 1
    cnt = 0
    for (a, b) in conds:
        if ds[a] >= 1 and ds[b] >= 1:
            cnt += 1
    # print ds
    res = max(res, cnt)
print res

'''
^^^TEST^^^
4 4
1 2
1 3
2 4
3 4
3
1 2
1 3
2 3
-----
2
$$$TEST$$$

^^^TEST^^^
4 4
1 2
1 3
2 4
3 4
4
3 4
1 2
2 4
2 4
----
4
$$$TEST$$$

^^^TEST^^^
6 12
2 3
4 6
1 2
4 5
2 6
1 5
4 5
1 3
1 2
2 6
2 3
2 5
5
3 5
1 4
2 6
4 6
5 6
----
9
$$$TEST$$$
'''
