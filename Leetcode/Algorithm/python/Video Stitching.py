class Solution(object):
    def videoStitching(self, clips, T):
        INF = 10 ** 10
        dp = [INF for i in xrange(T + 1)]
        dp[0] = 0
        for clip in sorted(clips):
            l, r = clip[0], min(T, clip[1])
            if l > T:
                continue
            mini = dp[l] + 1
            for i in xrange(l, r + 1):
                dp[i] = min(dp[i], mini)
        if dp[T] >= INF:
            return -1
        return dp[T]
