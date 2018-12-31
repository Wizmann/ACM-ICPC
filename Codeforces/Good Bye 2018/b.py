n = int(raw_input())

xs, ys = [], []
for i in xrange(n):
    (x, y) = map(int, raw_input().split())
    xs.append(x)
    ys.append(y)

xs.sort()
ys.sort()

dx, dy = [], []
for i in xrange(n):
    (x, y) = map(int, raw_input().split())
    dx.append(x)
    dy.append(y)
dx.sort(reverse=True)
dy.sort(reverse=True)

print xs[0] + dx[0], ys[0] + dy[0]
