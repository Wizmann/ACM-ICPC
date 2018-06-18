class Solution(object):
    def new21Game(self, N, K, W):
        if K == 0:
            return 1.0
        dp = [1.] + [0.0 for i in xrange(N)]
        tot = 1
        p, q = 0, 1
        for i in xrange(1, N + 1):
            dp[i] = 1.0 / W * tot
            if i < K:
                tot += dp[i]
            q += 1
            if q - p > W:
                tot -= dp[p]
                p += 1
        return sum(dp[K: N + 1])

