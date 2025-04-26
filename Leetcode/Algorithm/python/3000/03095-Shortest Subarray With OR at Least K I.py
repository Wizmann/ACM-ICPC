INF = 10 ** 10

class Solution(object):
    def minimumSubarrayLength(self, nums, k):
        mini = INF
        n = len(nums)
        for i in xrange(n):
            tot = 0
            for j in xrange(i, n):
                tot |= nums[j]
                if tot >= k:
                    mini = min(mini, j - i + 1)
        if mini >= INF:
            return -1
        return mini
