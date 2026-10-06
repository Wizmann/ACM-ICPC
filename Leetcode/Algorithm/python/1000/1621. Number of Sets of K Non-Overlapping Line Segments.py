MOD = (10 ** 9) + 7

class Solution(object):
    def numberOfSets(self, n, k):
        dp = [[0 for i in xrange(n - 1)] for i in xrange(2) ]
        p = 0
        dp[p] = [i + 1 for i in xrange(n - 1)]
        for i in xrange(k - 1):
            q = p ^ 1
            # print dp[p]
            dp[q] = [0 for j in xrange(n - 1)]
            pre = 0
            tot = 0
            for j in xrange(n - 1):
                dp[q][j] = tot
                tot += dp[p][j] + pre
                pre += dp[p][j]
                dp[q][j] %= MOD
                tot %= MOD
            p = q
        # print dp[p]
        return sum(dp[p]) % MOD
