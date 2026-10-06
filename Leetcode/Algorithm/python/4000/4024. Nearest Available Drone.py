INF = 10 ** 10

class Solution(object):
    def nearestDrone(self, drones, target):
        tx, ty = target
        minv, mini = INF, -1
        for i, (x, y, r) in enumerate(drones):
            dis = abs(x - tx) + abs(y - ty)
            # print i, r, dis
            if dis > r:
                continue
            if dis < minv:
                minv = dis
                mini = i
        return mini
