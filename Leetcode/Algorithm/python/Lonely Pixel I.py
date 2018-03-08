from collections import defaultdict

class Solution(object):
    def findLonelyPixel(self, picture):
        n = len(picture)
        m = len(picture[0])
        
        dy, dx = defaultdict(int), defaultdict(int)
        for i in xrange(n):
            for j in xrange(m):
                if picture[i][j] == 'B':
                    dy[i] += 1
                    dx[j] += 1
        res = 0
        for i in xrange(n):
            for j in xrange(m):
                if picture[i][j] == 'B':
                    if dy[i] == dx[j] == 1:
                        res += 1
        return res
