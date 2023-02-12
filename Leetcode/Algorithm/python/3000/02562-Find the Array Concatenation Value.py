class Solution(object):
    def findTheArrayConcVal(self, nums):
        res = 0
        while nums:
            if len(nums) == 1:
                res += nums[0]
                break
            res += int(str(nums[0]) + str(nums[-1]))
            nums = nums[1: -1]
        return res
