INF = 10 ** 10

class Solution(object):
    def shortestToChar(self, S, C):
        n = len(S)
        dp = [INF for i in xrange(n)]
        
        pre = -INF
        for i in xrange(n):
            if S[i] == C:
                pre = i
            dp[i] = min(dp[i], abs(i - pre))
            
        pre = INF
        for i in xrange(n - 1, -1, -1):
            if S[i] == C:
                pre = i
            dp[i] = min(dp[i], abs(pre - i))
        return dp
