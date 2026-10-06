class Solution:
    # @param n, an integer
    # @return an integer
    def climbStairs(self, n):
        stair = [0 for i in xrange(n + 1)]
        stair[0] = 1
        for i in xrange(n + 1):
            if i + 1 <= n:
                stair[i + 1] += stair[i]
            if i + 2 <= n:
                stair[i + 2] += stair[i]
        return stair[n]
