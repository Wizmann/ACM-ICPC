class BITree(object):
    def __init__(self, n):
        self.n = n + 1
        self.nums = [0 for i in xrange(self.n + 1)]
        
    def lowbit(self, x):
        return x & (-x)
    
    def add(self, pos, value):
        while pos < self.n:
            self.nums[pos] += value
            pos += self.lowbit(pos)
    
    def query(self, pos):
        res = 0
        while pos:
            res += self.nums[pos]
            pos -= self.lowbit(pos)
        return res
    
    def query_range(self, a, b):
        return self.query(b) - self.query(a - 1)


class Solution(object):
    def countRectangles(self, rectangles, points):
        rectangles.sort(reverse=True)
        points = map(lambda (i, (x, y)): (x, y, i), enumerate(points))
        points.sort(reverse=True)
        n = len(rectangles)
        m = len(points)
        bit = BITree(123)
        res = [0 for i in xrange(m)]
        p = 0
        for (x, y, i) in points:
            while p < len(rectangles) and rectangles[p][0] >= x:
                bit.add(rectangles[p][1], 1)
                p += 1
            res[i] = p - bit.query(y - 1)
        return res
                
