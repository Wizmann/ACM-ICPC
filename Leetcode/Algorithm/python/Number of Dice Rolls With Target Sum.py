TARGET = 1111
MOD = (10 ** 9) + 7

class Solution(object):
    def numRollsToTarget(self, d, f, target):
        dp = [[0 for i in xrange(TARGET)], [0 for i in xrange(TARGET)]]
        p = 0
        dp[0][0] = 1
        for i in xrange(d):
            q = p ^ 1
            dp[q] = [0 for i in xrange(TARGET)]
            for j in xrange(TARGET):
                for k in xrange(1, f + 1):
                    if dp[p][j] and j + k < TARGET:
                        dp[q][j + k] += dp[p][j]
                        dp[q][j + k] %= MOD
            p = q
        return dp[p][target] % MOD
