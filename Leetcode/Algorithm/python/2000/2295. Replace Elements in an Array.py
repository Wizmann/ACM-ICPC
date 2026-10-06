class Solution(object):
    def arrayChange(self, nums, operations):
        d = {}
        for i, num in enumerate(nums):
            d[num] = i
            
        for a, b in operations:
            idx = d[a]
            del d[a]
            nums[idx] = b
            d[b] = idx
        return nums
