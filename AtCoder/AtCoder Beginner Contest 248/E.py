from collections import defaultdict
import sys

INF = 10 ** 10

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def getK(dy, dx):
    if dx == 0:
        return (INF, 0)
    if dy == 0:
        return (0, 1)
    s = 1
    if dy * dx < 0:
        s = -1
    dy = abs(dy)
    dx = abs(dx)
    g = gcd(dy, dx)
    dy /= g
    dx /= g
    return (s * dy, dx)

def getC(k, y, x):
    if k == (INF, 0):
        return (x, 1)
    if k == (0, 1):
        return (y, 1)
    a, b = k
    a = y * b - x * a

    s = 1
    if a * b < 0:
        s = -1
    a = abs(a)
    b = abs(b)
    if a == 0:
        return (0, 1)
    assert b
    g = gcd(a, b)
    a /= g
    b /= g
    return (s * a, b)

(n, K) = map(int, raw_input().split())

if K == 1:
    print 'Infinity'
    sys.exit(0)

points = []
for i in xrange(n):
    x, y = map(int, raw_input().split())
    points.append((x, y))

d = defaultdict(set)

for i in xrange(n):
    for j in xrange(i + 1, n):
        x1, y1 = points[i]
        x2, y2 = points[j]

        k = getK(y1 - y2, x1 - x2)
        c = getC(k, y1, x1)

        # print i, j, k, c

        d[(k, c)].add(i)
        d[(k, c)].add(j)

res = 0
for (key, st) in d.items():
    if len(st) >= K:
        res += 1
    # print key, st
print res

'''
^^^^^^TEST^^^^
5 2
0 0
1 0
0 1
-1 0
0 -1
------
6
$$$TEST$$$$

^^^^^^TEST^^^^
1 1
0 0
------
Infinity
$$$TEST$$$$
'''
