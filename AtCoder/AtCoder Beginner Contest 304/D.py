#coding=utf-8
from collections import defaultdict

INF = 10 ** 100

w, h = map(int, raw_input().split())
n = int(raw_input())

ps = []
for i in xrange(n):
    (x, y) = map(int, raw_input().split())
    ps.append((x, y, i))
ps.sort(key=lambda (x, y, i): x)

na = int(raw_input())
As = [0] + map(int, raw_input().split()) + [w]
As.sort()

xs = [-1 for i in xrange(n)]

p = 0
for (x, y, idx) in ps:
    while x > As[p]:
        p += 1
    xs[idx] = p

ps.sort(key=lambda (x, y, i): y)

nb = int(raw_input())
Bs = [0] + map(int, raw_input().split()) + [h]
Bs.sort()

ys = [-1 for i in xrange(n)]

p = 0
for (x, y, idx) in ps:
    while y > Bs[p]:
        p += 1
    ys[idx] = p

d = defaultdict(int)
for i in xrange(n):
    u = xs[i] * (w + 1) + ys[i]
    d[u] += 1

mini, maxi = INF, -INF
if len(d) != (na + 1) * (nb + 1):
    mini = 0

maxi = max(d.values())
mini = min(mini, min(d.values()))

print mini, maxi

'''
^^^^^TEST^^^
7 6
5
6 1
3 1
4 2
1 5
6 2
2
2 5
2
3 4
----------
0 2
$$$$$$$TEST$$$$


^^^^^TEST^^^
4 4
4
1 1
3 1
3 3
1 3
1
2
1
2
----------
1 1
$$$$$$$TEST$$$$
'''

