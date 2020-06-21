INF = 10 ** 10

class Solution(object):
    def maxDotProduct(self, nums1, nums2):
        n, m = len(nums1), len(nums2)
        dp = [ [-INF for j in xrange(m + 1)] for i in xrange(n + 1) ]
        for i in xrange(n):
            for j in xrange(m):
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j], dp[i][j] + nums1[i] * nums2[j], nums1[i] * nums2[j])
        return dp[i + 1][j + 1]
