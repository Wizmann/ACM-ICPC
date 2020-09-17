# coding=utf-8
INF = 10 ** 10

n = int(raw_input())

ns = []

for i in xrange(n):
    (a, b) = map(int, raw_input().split())
    ns.append((a, b))
ns.append((INF, INF))
ns.sort()

res = 0
l, r = -INF, -INF
for (a, b) in ns:
    if a <= r:
        r = max(b, r)
    else:
        res += r - l
        l, r = a, b
print res



