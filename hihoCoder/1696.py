import math

n = int(raw_input())
ps = [map(int, raw_input().split()) for i in xrange(n)]

dis = 0
for i in xrange(n - 1):
    dis += math.sqrt(
        (ps[i][0] - ps[i + 1][0]) ** 2 +
        (ps[i][1] - ps[i + 1][1]) ** 2)

dis /= 2.

for i in xrange(n - 1):
    d = math.sqrt(
        (ps[i][0] - ps[i + 1][0]) ** 2 +
        (ps[i][1] - ps[i + 1][1]) ** 2)

    if d <= dis:
        dis -= d
    else:
        delta_y = ps[i + 1][1] - ps[i][1]
        delta_x = ps[i + 1][0] - ps[i][0]

        y = ps[i][1] + 1.0 * delta_y * dis / d
        x = ps[i][0] + 1.0 * delta_x * dis / d
        print '%.1f %.1f' % (y, x)
        break
