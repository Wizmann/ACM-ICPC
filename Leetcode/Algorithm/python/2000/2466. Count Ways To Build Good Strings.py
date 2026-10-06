MOD = (10 ** 9) + 7

class Solution(object):
    def countGoodStrings(self, low, high, zero, one):
        dp = [0 for i in xrange(high + 1)]
        dp[0] = 1
        for i in xrange(high + 1):
            if i + zero <= high:
                dp[i + zero] = (dp[i + zero] + dp[i]) % MOD
            if i + one <= high:
                dp[i + one] = (dp[i + one] + dp[i]) % MOD
        return sum(dp[low: high + 1]) % MOD
