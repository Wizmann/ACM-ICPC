class Solution(object):
    def findMaxAverage(self, nums, k):
        n = len(nums)
        s = sum(nums[:k])
        ans = s
        for i in xrange(k, n):
            s -= nums[i - k]
            s += nums[i]
            ans = max(ans, s)
        return 1.0 * ans / k
