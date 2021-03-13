INF = 10 ** 10

class Solution(object):
    def nearestValidPoint(self, x, y, points):
        mini = -1
        minv = INF
        for i, (xx, yy) in enumerate(points):
            if xx != x and yy != y:
                continue
            dis = abs(xx - x) + abs(yy - y)
            if dis < minv:
                mini = i
                minv = dis
        return mini
            
