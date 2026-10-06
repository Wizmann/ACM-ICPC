INF = 10 ** 10

class Solution(object):
    def minimumSumSubarray(self, nums, l, r):
        n = len(nums)
        mini = INF
        for i in xrange(n):
            for j in xrange(l, r + 1):
                if i + j <= n:
                    tot = sum(nums[i: i + j])
                    # print i, i + j, tot
                    if tot > 0:
                        mini = min(mini, tot)
        return -1 if mini >= INF else mini
