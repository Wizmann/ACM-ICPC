MOD = (10 ** 9) + 7

class Solution(object):
    def firstDayBeenInAllRooms(self, nextVisit):
        n = len(nextVisit)
        dp = [0 for i in xrange(n)]

        for i in xrange(1, n):
            dp[i] = (dp[i - 1] * 2 - dp[nextVisit[i - 1]] + 2) % MOD
        return dp[n - 1]
