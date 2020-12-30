from math import sqrt
from collections import defaultdict

INF = 10 ** 100

def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

def pdis(pa, pb):
    y1, x1 = pa
    y2, x2 = pb
    return (y1 - y2) ** 2 + (x1 - x2) ** 2
    
class Solution(object):
    def minAreaFreeRect(self, points):
        d = defaultdict(list)
        n = len(points)
        points.sort()
        for i in xrange(n):
            for j in xrange(i + 1, n):
                y1, x1 = points[i]
                y2, x2 = points[j]
                dy, dx = y1 - y2, x1 - x2
                dis = (y1 - y2) ** 2 + (x1 - x2) ** 2
                if dx == 0:
                    d[(INF, 1, dis)].append((i, j))
                elif dy == 0:
                    d[(0, 1, dis)].append((i, j))
                else:
                    s = 1
                    if dy * dx < 0:
                        s = -1
                    dy, dx = abs(dy), abs(dx)
                    g = gcd(dy, dx)
                    d[(dy / g, dx / g, dis)].append((i, j))
        ans = INF
        for key, values in d.items():
            m = len(values)
            for i in xrange(m):
                for j in xrange(i + 1, m):
                    (a1, b1), (a2, b2) = values[i], values[j]
                    if len(set([a1, b1, a2, b2])) != 4:
                        continue
                    p1, p2, p3, p4 = points[a1], points[b1], points[a2], points[b2]
                    if pdis(p1, p2) + pdis(p1, p3) != pdis(p2, p3) or \
                       pdis(p2, p1) + pdis(p2, p4) != pdis(p1, p4):
                        continue
                    #print p1, p2, p3, p4
                    ans = min(ans, pdis(p1, p2) * pdis(p1, p3))
        return 0 if ans == INF else sqrt(ans)
