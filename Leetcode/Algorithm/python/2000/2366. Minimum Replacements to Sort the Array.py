INF = 10 ** 10

class Solution(object):
    def minimumReplacement(self, nums):
        n = len(nums)
        step = 0
        pre = INF
        for i in xrange(n - 1, -1, -1):
            cur = nums[i]
            if pre >= cur:
                pre = cur
            else:
                k = (cur + pre - 1) / pre
                pre = cur / k
                step += k - 1
        return step
