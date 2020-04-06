# https://leetcode.com/problems/circle-and-rectangle-overlapping/
from math import sqrt

def point_dis(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

class Solution:
    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        points = [
            (x1, y1),
            (x1, y2),
            (x2, y1),
            (x2, y2)
        ]
        edges = [
            ((x1, y1), (x1, y2)),
            ((x1, y1), (x2, y1)),
            ((x2, y2), (x1, y2)),
            ((x2, y2), (x2, y1))
        ]
        
        for p in points:
            if point_dis((x_center, y_center), p) <= radius:
                return True
        if x1 <= x_center <= x2 and y1 <= y_center <= y2:
            return True
        print("ckp1")
        flag = False
        for (p1, p2) in edges:
            x1, y1 = p1
            x2, y2 = p2
            if x1 == x2:
                dr = abs(x_center - x1)
                if dr > radius:
                    continue
                cy = sqrt(radius ** 2 - dr ** 2) + y_center
                print(cy, max(y1, y2))
                if min(y1, y2) <= cy <= max(y1, y2):
                    return True
            else:
                assert y1 == y2
                dr = abs(y_center - y1)
                if dr > radius:
                    continue
                cx = sqrt(radius ** 2 - dr ** 2) + x_center
                print(cx, max(x1, x2))
                if min(x1, x2) <= cx <= max(x1, x2):
                    return True
        return False
