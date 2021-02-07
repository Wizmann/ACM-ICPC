import math

class Solution(object):
    def bestCoordinate(self, towers, radius):
        n = len(towers)
        towers.sort()
        maxi = -1
        maxp = (0, 0)
        for x1 in xrange(51):
            for y1 in xrange(51):
                cur = 0
                for j in xrange(n):
                    (x2, y2, q2) = towers[j]

                    dis = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
                    if dis > radius:
                        continue
                    else:
                        cur += int(q2 / (1 + dis))
                if cur > maxi:
                    maxi = cur
                    maxp = (x1, y1)
        return maxp
