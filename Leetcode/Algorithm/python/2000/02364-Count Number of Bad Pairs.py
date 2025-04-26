from collections import defaultdict

class Solution(object):
    def countBadPairs(self, nums):
        d = defaultdict(int)
        
        for i, num in enumerate(nums):
            d[num - i] += 1
            
        tot = len(nums) * (len(nums) - 1) / 2
        for _, count in d.items():
            tot -= count * (count - 1) / 2
        return tot
        
