from collections import Counter

class Solution(object):
    def canDivideIntoSubsequences(self, nums, K):
        c = Counter(nums)
        l = max(c.values())
        r = len(nums)
        
        return r / l >= K
