class Solution(object):
    def superEggDrop(self, K, N):
        dp = [[0 for i in xrange(K + 1)] for j in xrange(N + 1)]
        
        for i in xrange(1, N + 1):
            for j in xrange(1, K + 1):
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + 1
                if dp[i][j] >= N:
                    return i
        return INF
