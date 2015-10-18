class Solution(object):
    def numDecodings(self, s):
        if not s or s[0] == '0':
            return 0
            
        n = len(s)
        dp = [0 for i in xrange(n + 1)]
        dp[0] = 1
        
        for i, c in enumerate(s):
            if i - 1 >= 0:
                u = s[i - 1] + c
                if u[0] != '0' and int(u) != 0 and int(u) <= 26:
                    dp[i + 1] += dp[i - 1]
            
            if c != '0':
                dp[i + 1] += dp[i]
        return dp[-1]
