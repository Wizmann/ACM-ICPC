class Solution(object):
    def maximizeGreatness(self, nums):
        n = len(nums)
        nums.sort()
        p, q = 0, 0
        res = 0
        while p < n and q < n:
            while q < n and nums[q] <= nums[p]:
                q += 1
            if q < n:
                p += 1
                q += 1
                res += 1
        return res
