INF = 10 ** 10

class Solution(object):
    def minDifference(self, nums):
        nums.sort()
        if len(nums) <= 4:
            return 0
        n = len(nums)
        mini = INF
        for i in xrange(4):
            l = nums[i]
            r = nums[n - 4 + i]
            mini = min(mini, r - l)
        return mini
        
