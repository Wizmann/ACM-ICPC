INF = 10 ** 10

class Solution(object):
    def minArea(self, image, x, y):
        minx, miny = INF, INF
        maxx, maxy = -INF, -INF
        
        n = len(image)
        m = len(image[0])
        
        for i in xrange(n):
            for j in xrange(m):
                if image[i][j] == '1':
                    minx, miny = min(minx, j), min(miny, i)
                    maxx, maxy = max(maxx, j), max(maxy, i)
        print minx, maxx, miny, maxy
        return (maxx - minx + 1) * (maxy - miny + 1)
        
