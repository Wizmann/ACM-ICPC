from collections import Counter

class Solution(object):
    def findShortestSubArray(self, nums):
        c = Counter(nums)
        maxi = max([c[k] for k in c])
        ans = 10 ** 10
        for k in c:
            v = c[k]
            if v == maxi:
                l, r = nums.index(k), len(nums) - nums[::-1].index(k) - 1
                ans = min(ans, r - l + 1)
        return ans
