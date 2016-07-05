import sys
sys.stdin = open('input.txt')

class Vector(object):
    def __init__(self, p0, p1):
        self.x = p0[0] - p1[0]
        self.y = p0[1] - p1[1]

    def xmult(self, v1):
        return self.x * v1.y - self.y * v1.x

n = int(raw_input())
points = []
for i in xrange(n):
    (x, y) = map(int, raw_input().split())
    points.append( (x, y) )

ans = 0
for i in xrange(n):
    pre = (i - 1)
    next = (i + 1) % n

    v1 = Vector(points[i], points[pre])
    v2 = Vector(points[next], points[i])

    if v1.xmult(v2) > 0:
        ans += 1

print ans
