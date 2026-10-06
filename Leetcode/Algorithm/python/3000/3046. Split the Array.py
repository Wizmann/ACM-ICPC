from collections import Counter

class Solution(object):
    def isPossibleToSplit(self, nums):
        c = Counter(nums)
        for (key, count) in c.items():
            if count > 2:
                return False
        return True
