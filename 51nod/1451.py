import sys

INF = 0x3f3f3f3f

def gcd(a, b):
    while a % b != 0:
        a, b = b, a % b
    return b

def get_slope(x, y):
    if x == 0:
        return (INF, 0)
    
    if y == 0:
        return (0, 0)
    s = x * y / abs(x * y)
    x, y = abs(x), abs(y)
    g = gcd(x, y)
    x, y = x / g, y / g
    return (s * x, y)

n = int(raw_input())
points = []
for i in xrange(n):
    (x, y) = map(int, raw_input().split())
    points.append( (x, y) )

if n < 3:
    print 0
    sys.exit(0)

ans = n * (n - 1) * (n - 2) / 6

for i in xrange(n):
    d = {}
    for j in xrange(i + 1, n):
        delta_x = points[i][0] - points[j][0]
        delta_y = points[i][1] - points[j][1]
        slope = get_slope(delta_x, delta_y)
        d[slope] = d.get(slope, 0) + 1

    for (key, value) in d.items():
        ans -= value * (value - 1) / 2

print ans
