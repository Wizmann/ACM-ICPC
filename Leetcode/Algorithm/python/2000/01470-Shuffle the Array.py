from itertools import chain

class Solution(object):
    def shuffle(self, nums, n):
        return chain.from_iterable(zip(nums[:n], nums[n:]))
