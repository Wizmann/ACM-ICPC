class Solution(object):
    def findColumnWidth(self, grid):
        n = len(grid[0])
        res = [0 for i in xrange(n)]
        for row in grid:
            for i, num in enumerate(row):
                res[i] = max(res[i], len(str(num)))
        return res
