class Solution(object):
    def pivotIndex(self, nums):
        s = sum(nums)
        l = 0
        for i, num in enumerate(nums):
            if l == s - num:
                return i
            l += num
            s -= num
        return -1
