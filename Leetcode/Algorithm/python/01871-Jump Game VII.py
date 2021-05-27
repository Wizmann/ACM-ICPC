class Solution(object):
    def canReach(self, s, minJump, maxJump):
        n = len(s)
        dp = [0 for i in xrange(n)]
        dp[0] = 1
        pre = 0
        for i in xrange(1, n):
            if i - maxJump - 1 >= 0:
                pre -= dp[i - maxJump - 1]
            if i - minJump >= 0:
                pre += dp[i - minJump]
            if s[i] == '0' and pre:
                dp[i] = 1
        return dp[n - 1]
