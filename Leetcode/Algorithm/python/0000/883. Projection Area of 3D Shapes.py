class Solution(object):
    def projectionArea(self, grid):
        points = []
        for y in xrange(len(grid)):
            line = grid[y]
            for x in xrange(len(line)):
                zs = line[x]
                for z in xrange(zs):
                    points.append((y, x, z))
        fs = [
            lambda p: (p[0], p[1]),
            lambda p: (p[1], p[2]),
            lambda p: (p[0], p[2])
        ]
        
        ans = 0
        for f in fs:
            s = set()
            for p in points:
                s.add(f(p))
            ans += len(s)
        return ans
