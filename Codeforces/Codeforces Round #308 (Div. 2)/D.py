import sys
from fractions import gcd

class Point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

def get_slope(pa, pb):
    delta_x = pa.x - pb.x
    delta_y = pa.y - pb.y
    
    if delta_x == 0:
        return (0, 0)
    if delta_y == 0:
        return (0xdeadbeef, 0xdeadbeef)
    g = gcd(abs(delta_x), abs(delta_y))
    if delta_x * delta_y < 0:
        delta_x = -abs(delta_x)
        delta_y = abs(delta_y)
    else:
        delta_x = abs(delta_x)
        delta_y = abs(delta_y)
    return (delta_y / g, delta_x / g)

n = int(raw_input())
points = []
for i in xrange(n):
    (a, b) = map(int, raw_input().split())
    points.append(Point(a, b))

ans = 0
for i in xrange(n):
    slope = {}
    tot = 0
    for j in xrange(i + 1, n):
        s = get_slope(points[i], points[j])
        ans += tot - slope.get(s, 0)
        slope[s] = slope.get(s, 0) + 1
        tot += 1
print ans
