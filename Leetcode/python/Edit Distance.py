class Solution:
    # @return an integer
    def minDistance(self, word1, word2):
        n, m = len(word1), len(word2)
        dp =[[0 for i in xrange(m + 1)] for j in xrange(n + 1)]
        
        for i in xrange(n + 1):
            dp[i][0] = i
        for i in xrange(m + 1):
            dp[0][i] = i
        
        for i in xrange(n):
            for j in xrange(m):
                delta = 1 if word1[i] != word2[j] else 0
                dp[i + 1][j + 1] = min(dp[i][j] + delta , dp[i][j + 1] + 1, dp[i + 1][j] + 1)
        return dp[n][m]
