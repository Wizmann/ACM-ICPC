INF = 10 ** 100

class Solution(object):
    def maxScore(self, grid):
        n = len(grid)
        m = len(grid[0])

        dp = [ [INF for j in xrange(m + 1)] for i in xrange(n + 1) ]

        maxi = -INF
        for i in xrange(1, n + 1):
            for j in xrange(1, m + 1):
                mini = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1])
                maxi = max(maxi, grid[i - 1][j - 1] - mini)
                dp[i][j] = min(dp[i][j], mini, grid[i - 1][j - 1])

        return maxi

'''
^^^^^TEST^^^^^
[[9,5,7,3],[8,9,6,1],[6,7,14,3],[2,5,3,1]]
--------------
9
$$$$TEST$$$$$

^^^^^TEST^^^^^
[[4,3,2],[3,2,1]]
--------------
-1
$$$$TEST$$$$$
'''
