class Solution(object):
    def xorGame(self, nums):
        if reduce(lambda x, y: x ^ y, nums) == 0:
            return True
        return len(nums) % 2 == 0
