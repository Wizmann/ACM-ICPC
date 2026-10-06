from collections import Counter

class Solution(object):
    def findLHS(self, nums):
        if not nums:
            return 0
        c = Counter(nums)
        ans = 0
        for key, value in c.items():
            a = value
            b = c[key + 1]
            if a and b:
                ans = max(ans, a + b)
        return ans
