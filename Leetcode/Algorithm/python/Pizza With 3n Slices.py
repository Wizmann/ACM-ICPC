INF = 10 ** 10

class Solution(object):
    def maxSizeSlices(self, slices):
        return max(self.solve([-INF] + slices[1:]), self.solve(slices[:-1] + [-INF]))

    def solve(self, slices):
        n = len(slices)
        dp = [ [0 for i in xrange(n)] for j in xrange(n / 3) ]
        
        for i in xrange(n / 3):
            for j in xrange(n):
                if i == 0:
                    dp[i][j] = slices[j]
                    if j - 1 >= 0:
                        dp[i][j] = max(dp[i][j], dp[i][j - 1])
                else:
                    if j - 2 >= 0:
                        dp[i][j] = slices[j] + dp[i - 1][j - 2]
                    if j - 1 >= 0:
                        dp[i][j] = max(dp[i][j], dp[i][j - 1])
        return max(dp[n / 3 - 1])
