import random
class Solution(object):
    def __init__(self, nums):
        self.nums = nums       

    def pick(self, target):
        return random.choice([i for (i, num) in enumerate(self.nums) if num == target])
