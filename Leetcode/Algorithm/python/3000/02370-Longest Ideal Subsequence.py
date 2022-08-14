ALPHA = 26

class Solution(object):
    def longestIdealString(self, s, k):
        n = len(s)
        dp = [0 for i in xrange(ALPHA)]
        
        for i in xrange(n):
            c = ord(s[i]) - ord('a')
            dp2 = dp[:]
            for j in xrange(ALPHA):
                if abs(c - j) <= k:
                    dp2[c] = max(dp2[c], dp[j] + 1)
            dp = dp2
        return max(dp)
            
        
