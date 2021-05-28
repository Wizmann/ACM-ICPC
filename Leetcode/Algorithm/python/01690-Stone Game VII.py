INF = 10 ** 10

class Solution(object):
    def stoneGameVII(self, stones):
        n = len(stones)
        pre = stones
        for i in xrange(1, n):
            pre[i] += pre[i - 1]
            
        def presum(a, b):
            return pre[b] - (0 if a == 0 else pre[a - 1])
        
        dp = [ [0 for i in xrange(n)] for j in xrange(n) ]
        for i in xrange(1, n):
            for j in xrange(n):
                if i + j < n:
                    dp[j][j + i] = max(presum(j, j + i - 1) - dp[j][j + i - 1], presum(j + 1, j + i) - dp[j + 1][j + i])
        # print dp
        return dp[0][n - 1]
        
