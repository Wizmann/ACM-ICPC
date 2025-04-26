MOD = (10 ** 9) + 7
INF = 10 ** 10

class Solution(object):
    def maxProductPath(self, grid):
        n = len(grid)
        m = len(grid[0])
        
        dp1 = [ [-INF for j in xrange(m)] for i in xrange(n) ]
        dp2 = [ [INF for j in xrange(m)] for i in xrange(n) ]
        
        dp1[0][0] = grid[0][0]
        dp2[0][0] = grid[0][0]
        
        for i in xrange(n):
            for j in xrange(m):
                if i - 1 >= 0:
                    dp1[i][j] = max(
                        dp1[i][j], 
                        grid[i][j] * dp1[i - 1][j],
                        grid[i][j] * dp2[i - 1][j])
                    dp2[i][j] = min(
                        dp2[i][j],
                        grid[i][j] * dp1[i - 1][j],
                        grid[i][j] * dp2[i - 1][j])
                if j - 1 >= 0:
                    dp1[i][j] = max(
                        dp1[i][j], 
                        grid[i][j] * dp1[i][j - 1],
                        grid[i][j] * dp2[i][j - 1])
                    dp2[i][j] = min(
                        dp2[i][j],
                        grid[i][j] * dp1[i][j - 1],
                        grid[i][j] * dp2[i][j - 1])
        res = dp1[n - 1][m - 1]
        if res < 0:
            return -1
        return dp1[n - 1][m - 1] % MOD

        
