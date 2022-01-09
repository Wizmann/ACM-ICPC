class Solution(object):
    def countVowelStrings(self, n):
        dp = [1, 1, 1, 1, 1]
        for i in xrange(n - 1):
            dp = [sum(dp[i:]) for i in xrange(5)]
        return sum(dp)
