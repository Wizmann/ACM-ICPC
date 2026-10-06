INF = 10 ** 10

class Solution(object):
    def maxSumAfterPartitioning(self, A, K):
        n = len(A)
        dp = [-INF for i in xrange(n)]
                
        for i in xrange(n):
            pre = 0 if i == 0 else dp[i - 1]
            maxi = 0
            for j in xrange(i, min(n, i + K)):
                maxi = max(maxi ,A[j])
                dp[j] = max(dp[j], pre + maxi * (j - i + 1))
        return dp[-1]
        
