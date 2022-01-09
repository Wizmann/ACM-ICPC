from math import sqrt

eps = 1e-8

class Solution(object):
    def largestTriangleArea(self, points):
        n = len(points)
        ans = 0
        for i in xrange(n):
            for j in xrange(i + 1, n):
                for k in xrange(j + 1, n):
                    p1, p2, p3 = points[i], points[j], points[k]
                    
                    a = self.dis(p1, p2)
                    b = self.dis(p2, p3)
                    c = self.dis(p1, p3)
                    
                    if a == 0 or b == 0 or c == 0:
                        continue
                    
                    s = (a + b + c) / 2
                    if s * (s - a) * (s - b) * (s - c) <= eps:
                        continue
                    ans = max(ans, sqrt(s * (s - a) * (s - b) * (s - c)))
        return ans
    
    def dis(self, a, b):
        return sqrt(((a[0] - b[0]) ** 2) + ((a[1] - b[1]) ** 2))
