from collections import defaultdict

class Solution(object):
    def kClosest(self, points, K):
        return sorted(points, key=lambda (x, y): x * x + y * y)[:K]
