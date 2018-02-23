"""
class Point:
    def __init__( self, x=0, y=0):
       	self.x = x
       	self.y = y
"""

from collections import Counter

class Solution:
    """
    @param pointSet: The point set
    @return: The answer
    """
    def rectangle(self, pointSet):
        s = map(lambda p: (p.x, p.y), pointSet)
        xs = Counter(map(lambda p: p.x, pointSet))
        ys = Counter(map(lambda p: p.y, pointSet))
        pointSet = filter(lambda p: xs[p.x] > 1 and ys[p.y] > 1, pointSet)
        n = len(pointSet)
        for i in xrange(n):
            p1 = pointSet[i]
            for j in xrange(i + 1, n):
                p2 = pointSet[j]
                if p1.x == p2.x or p1.y == p2.y:
                    continue
                p3 = (p1.x, p2.y)
                p4 = (p2.x, p1.y)
                
                if p3 in s and p4 in s:
                    return "YES"
        return "NO"
