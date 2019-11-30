MOD = (10 ** 9) + 7

class Solution(object):
    def numWays(self, steps, arrLen):
        n = min(steps, arrLen)
        dp = [ [0 for i in xrange(n)] for j in xrange(2) ]
        p = 0
        dp[0][0] = 1
        for i in xrange(steps):
            q = p ^ 1
            dp[q] = [0 for i in xrange(n)]
            
            for j in xrange(n):
                dp[q][j] += dp[p][j] + (dp[p][j - 1] if j - 1 >= 0 else 0) + (dp[p][j + 1] if j + 1 < n else 0)
                dp[q][j] %= MOD
            p = q
        return dp[p][0]
            
