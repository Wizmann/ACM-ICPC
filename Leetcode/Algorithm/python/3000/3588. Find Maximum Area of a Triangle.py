from collections import defaultdict
INF = 10 ** 10
class Solution(object):
    def maxArea(self, coords):
        return max(self.do_maxArea(coords, lambda (x, y): x, lambda (x, y): y),
                   self.do_maxArea(coords, lambda (x, y): y, lambda (x, y): x))

    def do_maxArea(self, coords, getX, getY):
        d = defaultdict(lambda: (INF, -INF))
        miny, maxy = INF, -INF
        for p in coords:
            x = getX(p)
            y = getY(p)
            d[y] = (min(d[y][0], x), max(d[y][1], x))
            miny = min(miny, y)
            maxy = max(maxy, y)
        res = -1
        for (y, xs) in d.items():
            minx, maxx = xs
            a = maxx - minx
            if a == 0:
                continue
            b = max(abs(y - miny), abs(y - maxy))
            if b == 0:
                continue
            res = max(res, a * b)
        return res
