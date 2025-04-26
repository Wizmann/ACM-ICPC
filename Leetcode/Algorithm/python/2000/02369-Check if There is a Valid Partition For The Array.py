class Solution(object):
    def validPartition(self, nums):
        n = len(nums)
        dp = [0 for i in xrange(n + 1)]
        dp[0] = 1
        for i, num in enumerate(nums):
            if not dp[i + 1] and i - 1 >= 0 and self.check1(nums[i - 1: i + 1]):
                dp[i + 1] |= dp[i - 1]
            if not dp[i + 1] and i - 2 >= 0 and self.check2(nums[i - 2: i + 1]):
                dp[i + 1] |= dp[i - 2]
            if not dp[i + 1] and i - 2 >= 0 and self.check3(nums[i - 2: i + 1]):
                dp[i + 1] |= dp[i - 2]
        return True if dp[-1] else False
        
    def check1(self, nums):
        assert len(nums) == 2
        return nums[0] == nums[1]
    
    def check2(self, nums):
        assert len(nums) == 3
        return nums[0] == nums[1] == nums[2]
    
    def check3(self, nums):
        assert len(nums) == 3
        return nums[0] + 2 == nums[1] + 1 == nums[2]
