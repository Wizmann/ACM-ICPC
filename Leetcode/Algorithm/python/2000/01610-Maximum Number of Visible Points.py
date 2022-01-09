from math import atan2, degrees

class Solution(object):
    def visiblePoints(self, points, angle, location):
        ps = []
        x, y = location
        same = 0
        for (nx, ny) in points:
            dy = ny - y
            dx = nx - x
            if dy == 0 and dx == 0:
                same += 1
                continue
            r = degrees(math.atan2(dy, dx))
            ps.append(r)
        # print ps
        ps += map(lambda x: x + 360, ps)
        ps.sort()
        p, q = 0, 0
        m = len(ps)
        res = 0
        print ps
        while p <= q:
            q = max(p, q)
            while q < m and ps[q] - ps[p] <= angle:
                q += 1
            res = max(res, q - p + same)
            p += 1
        return res
                
