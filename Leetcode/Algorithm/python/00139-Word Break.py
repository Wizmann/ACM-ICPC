class Solution(object):
    def wordBreak(self, s, wordDict):
        st = set(wordDict)
        n = len(s)
        dp = [0 for i in xrange(n + 1)]
        dp[0] = 1
        
        for i in xrange(n):
            for j in xrange(i + 1):
                snippet = s[j: i + 1]
                if snippet in st:
                    dp[i + 1] |= dp[j]
        return dp[n] == 1
