class Solution(object):
    def findMiddleIndex(self, nums):
        tot = sum(nums)
        pre = 0
        for i, num in enumerate(nums):
            tot -= num
            if pre == tot:
                return i
            pre += num
        return -1
