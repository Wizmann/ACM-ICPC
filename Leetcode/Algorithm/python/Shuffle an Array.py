import random

class Solution(object):

    def __init__(self, nums):
        self.nums = nums
        self.origin_nums = nums[:]
        

    def reset(self):
        self.nums = self.origin_nums[:]
        return self.nums

    def shuffle(self):
        n = len(self.nums)
        for i in xrange(n):
            idx = random.randint(0, n - i - 1)
            self.nums[n - i - 1], self.nums[idx] = self.nums[idx], self.nums[n - i - 1]
        return self.nums
