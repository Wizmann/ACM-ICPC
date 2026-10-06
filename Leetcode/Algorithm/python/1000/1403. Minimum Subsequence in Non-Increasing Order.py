# https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/

class Solution(object):
    def minSubsequence(self, nums):
        nums.sort()
        tot = sum(nums)
        rem = tot
        
        while len(nums) > 1 and (rem - min(nums[0], nums[-1])) * 2 > tot:
            if nums[0] < nums[-1]:
                rem -= nums.pop(0)
            else:
                rem -= nums.pop(-1)
        return sorted(nums, reverse=True)
