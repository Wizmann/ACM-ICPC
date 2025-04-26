class Solution:
    # @return an integer
    def uniquePaths(self, m, n):
        ans = 1
        m -= 1
        n -= 1
        for i in xrange(min(m, n)):
            ans *= (m + n - i)
            ans /= i + 1
        return ans
