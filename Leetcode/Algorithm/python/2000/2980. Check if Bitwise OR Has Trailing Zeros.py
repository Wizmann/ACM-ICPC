class Solution(object):
    def hasTrailingZeros(self, nums):
        evens = filter(lambda x: x % 2 == 0, nums)
        return len(evens) >= 2
