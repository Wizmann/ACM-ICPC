class Solution(object):
    def probabilityOfHeads(self, prob, target):
        n = len(prob)
        dp = [0 for i in xrange(n + 1)]
        dp[0] = 1
        
        for i in xrange(n):
            ndp = [0 for j in xrange(n + 1)]
            p = prob[i]
            for j in xrange(i + 1):
                ndp[j + 1] += dp[j] * p
                ndp[j] += dp[j] * (1 - p)
            dp = ndp
        return dp[target]
