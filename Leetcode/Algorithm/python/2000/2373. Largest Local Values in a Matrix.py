INF = 10 ** 100

class Solution(object):
    def largestLocal(self, grid):
        n = len(grid)
        mat = [ [-INF for i in xrange(n - 2)] for j in xrange(n - 2) ]
        
        for i in xrange(n - 2):
            for j in xrange(n - 2):
                maxi = -INF
                for di in xrange(3):
                    for dj in xrange(3):
                        maxi = max(maxi, grid[i + di][j + dj])
                mat[i][j] = maxi
        return mat
            
