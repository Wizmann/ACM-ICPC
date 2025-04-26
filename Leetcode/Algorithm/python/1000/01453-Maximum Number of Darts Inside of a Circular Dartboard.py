from math import sqrt

def CenterX(x1, y1, x2, y2, r):
    d = 1.0 * ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))
    x3 = (x1 + x2) / 2.0
    return (
        x3 + sqrt(r * r - d / 4) * (y2 - y1) / sqrt(d),
        x3 - sqrt(r * r - d / 4) * (y2 - y1) / sqrt(d)
    )

def CenterY(x1, y1, x2, y2, r):
    d = 1.0 * ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))
    y3 = (y1 + y2) / 2.0
    return (
        y3 - sqrt(r * r - d / 4) * (x2 - x1) / sqrt(d),
        y3 + sqrt(r * r - d / 4) * (x2 - x1) / sqrt(d)
    )

class Solution(object):
    def numPoints(self, points, r):
        n = len(points)
        res = 1
        for i in xrange(n):
            for j in xrange(n):
                if i == j:
                    continue
                x1, y1 = points[i]
                x2, y2 = points[j]
                if (x1 - x2) ** 2 + (y1 - y2) ** 2 > r * r * 4:
                    continue

                x0s = CenterX(points[i][0], points[i][1], points[j][0], points[j][1], r)
                y0s = CenterY(points[i][0], points[i][1], points[j][0], points[j][1], r)
                for (x0, y0) in zip(x0s, y0s):
                    tot = 0
                    for p in points:
                        x, y = p
                        dis = (x - x0) ** 2 + (y - y0) ** 2
                        if dis <= r * r + 0.001:
                            tot += 1
                    # print x0, y0, tot
                    res = max(res, tot)
        return res
                    
