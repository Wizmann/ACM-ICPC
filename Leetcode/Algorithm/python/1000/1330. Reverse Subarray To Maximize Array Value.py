INF = 10 ** 10

class Solution(object):
    def maxValueAfterReverse(self, nums):
        n = len(nums)
        
        res = 0
        for i in xrange(1, n):
            res += abs(nums[i] - nums[i - 1])
            
        a = 0
        for i in xrange(1, n):
            a = max(a,
                    abs(nums[i - 1] - nums[-1]) - abs(nums[i - 1] - nums[i]),
                    abs(nums[i] - nums[0]) - abs(nums[i - 1] - nums[i])
                   )
        mini = INF
        maxi = -INF
        for i in xrange(1, n):
            mini = min(mini, max(nums[i - 1], nums[i]))
            maxi = max(maxi, min(nums[i], nums[i - 1]))
        b = (maxi - mini) * 2
        return res + max(a, b)
