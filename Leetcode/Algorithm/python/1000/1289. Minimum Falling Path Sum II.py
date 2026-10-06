INF = 10 ** 10

class Solution(object):
    def minFallingPathSum(self, arr):
        n = len(arr)
        dp = [0 for i in xrange(n)]
        for i in xrange(n):
            nxt = [0 for j in xrange(n)]
            for j in xrange(n):
                cur = min(dp[:j] + dp[j + 1:]) + arr[i][j]
                nxt[j] = cur
            dp = nxt
        return min(dp)
