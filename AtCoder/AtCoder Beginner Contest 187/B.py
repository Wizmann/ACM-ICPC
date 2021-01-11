n = int(raw_input())

ps = []
for i in xrange(n):
    (x, y) = map(int, raw_input().split())
    ps.append((x, y))

cnt = 0
for i in xrange(n):
    for j in xrange(i + 1, n):
        ka = ps[i][0] - ps[j][0]
        kb = ps[i][1] - ps[j][1]

        if abs(kb) <= abs(ka):
            cnt += 1
print cnt

'''
^^^TEST^^^
3
0 0
1 2
2 1
----
2
$$$TEST$$$

^^^TEST^^^
1
-691 273
----
0
$$$TEST$$$

^^^TEST^^^
10
-31 -35
8 -36
22 64
5 73
-14 8
18 -58
-41 -85
1 -88
-21 -85
-11 82
----
11
$$$TEST$$$
'''
