N = 60
 
(x0, y0, ax, ay, bx, by) = map(int, raw_input().split())
(xs, ys, t) = map(int, raw_input().split())
 
tot = 0
cnt = 1
ps = [(y0, x0)]
for i in xrange(N):
    x1 = ax * x0 + bx
    y1 = ay * y0 + by
    ps.append((y1, x1))
    x0, y0 = x1, y1
 
tot = 0
res = 0
for i in xrange(N):
    p = ps[i]
    cur = t - (abs(xs - p[1]) + abs(ys - p[0]))
 
    tot = 0
    for j in xrange(i, -1, -1):
        cur -= abs(p[0] - ps[j][0]) + abs(p[1] - ps[j][1])
        if cur >= 0:
            tot += 1
        if cur < 0:
            break
        p = ps[j]
    res = max(res, tot)
 
for i in xrange(N):
    p = ps[i]
    cur = t - (abs(xs - p[1]) + abs(ys - p[0]))
 
    tot = 0
    for j in xrange(i, N):
        cur -= abs(p[0] - ps[j][0]) + abs(p[1] - ps[j][1])
        if cur >= 0:
            tot += 1
        if cur < 0:
            break
        p = ps[j]
    res = max(res, tot)
 
print res
