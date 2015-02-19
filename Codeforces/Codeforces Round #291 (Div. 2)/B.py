from fractions import gcd

INF = 0x3f3f3f3f

def get_slope(a, b):
    (x0, y0) = a
    (x1, y1) = b

    delta_x = x0 - x1
    delta_y = y0 - y1

    if delta_x == 0:
        return (0, 0)
    if delta_y == 0:
        return (0, -1)

    s = 1 if delta_x * delta_y > 0 else -1
    delta_x = abs(delta_x)
    delta_y = abs(delta_y)

    g = gcd(delta_x, delta_y)
    delta_x /= g
    delta_y /= g

    return (delta_x * s, delta_y)

(n, x0, y0) = map(int, raw_input().split())

ghosts = [tuple(map(int, raw_input().split()))
        for i in xrange(n)]

s = set([])

for i in xrange(n):
    a = get_slope(ghosts[i], (x0, y0))
    s.add(a)

print len(s)
