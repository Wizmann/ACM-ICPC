from collections import defaultdict

n = int(raw_input())

d = defaultdict(list)

for i in xrange(n):
    (x, y) = map(int, raw_input().split())
    d[x].append(y)

d2 = defaultdict(int)
for _, vs in d.items():
    m = len(vs)
    vs.sort()
    for i in xrange(m):
        for j in xrange(i + 1, m):
            a, b = vs[i], vs[j]
            d2[(a, b)] += 1

res = 0
for _, v in d2.items():
    res += v * (v - 1) / 2
print res

'''
^^^TEST^^^
6
0 0
0 1
1 0
1 1
2 0
2 1
-----
3
$$$TEST$$$

^^^TEST^^^
4
0 1
1 2
2 3
3 4
-------
0
$$$TEST$$$

^^^TEST^^^
7
0 1
1 0
2 0
2 1
2 2
3 0
3 2
-----
1
$$$TEST$$$
'''



