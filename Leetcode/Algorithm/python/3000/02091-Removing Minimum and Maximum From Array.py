class Solution(object):
    def minimumDeletions(self, nums):
        n = len(nums)
        mini = nums.index(min(nums))
        maxi = nums.index(max(nums))
        
        return min(max(mini, maxi) + 1, max(n - mini, n - maxi), mini + 1 + n - maxi, n - mini + maxi + 1)
