class Solution(object):
    def findPairs(self, nums, k):
        if k == 0:
            d = {}
            for a in nums:
                d[a] = d.get(a, 0) + 1
            return len(filter(lambda (x, y): y > 1, d.items()))
        if k < 0:
            return 0
        s = set(nums)
        ans = 0
        for a in s:
            if a - k in s:
                ans += 1
        return ans
