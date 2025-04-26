from collections import Counter, defaultdict

INF = 10 ** 100
MOD = 10 ** 9 + 7

class Solution(object):
    def countSubMultisets(self, nums, l, r):
        N = r + 12
        c = Counter(nums)
        zeros = c[0]
        del c[0]
        c = sorted(c.items())

        dp = [0 for i in xrange(N)]
        dp[0] = 1

        for (k, v) in c:
            d = defaultdict(int)
            dp2 = [0 for i in xrange(N)]
            for i in xrange(k, N):
                d[i % k] += dp[i - k]
                if i >= (v + 1) * k:
                    d[i % k] -= dp[i - (v + 1) * k]
                dp2[i] += d[i % k]

            for i in xrange(1, N):
                dp[i] = dp[i] + dp2[i]

        res = 0
        for i in xrange(l, r + 1):
            res += dp[i]
            res %= MOD
        res = res * (zeros + 1) % MOD
        # print dp[:r + 1]
        return res

