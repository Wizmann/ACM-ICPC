class Solution:
    # @param nums: an integer[]
    # @return: an integer
    def maxProduct(self, nums):
        if len(nums) == 1:
            return nums[0]
            
        maxi = 1
        mini = 1
        ans = -0xdeadbeef
        
        for cur in nums:
            a = maxi * cur
            b = mini * cur
            
            ans = max(ans, a, b, cur)
            
            maxi = max(cur, a, b)
            mini = min(cur, a, b)
        
        return ans
