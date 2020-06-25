INF = 10 ** 10

class Solution(object):
    def cherryPickup(self, grid):
        n = len(grid)
        m = len(grid[0])
        
        dp = [[[-INF for k in xrange(m)] for j in xrange(m)] for i in xrange(2)]
        
        dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1]
        res = -INF
        p = 0
        for i in xrange(1, n):
            q = p ^ 1
            for a in xrange(m):
                for b in xrange(m):
                    maxi = -INF
                    for pa in xrange(max(0, a - 1), min(a + 1, m - 1) + 1):
                        for pb in xrange(max(0, b - 1), min(b + 1, m - 1) + 1):
                            maxi = max(maxi, dp[p][pa][pb])
                        
                    if a == b:
                        cur = grid[i][a]
                    else:
                        cur = grid[i][a] + grid[i][b]
                    dp[q][a][b] = max(dp[q][a][b], maxi + cur)
                    res = max(res, dp[q][a][b])
            p = q
        return res
