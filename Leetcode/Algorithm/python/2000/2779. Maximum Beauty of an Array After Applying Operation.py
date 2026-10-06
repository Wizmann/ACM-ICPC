class Solution(object):
    def maximumBeauty(self, nums, k):
        nums.sort()
        n = len(nums)
        p, q = 0, 0
        res = 0
        while p < n and q < n:
            while q < n and nums[q] - nums[p] <= 2 * k:
                q += 1
            res = max(res, q - p)
            p += 1
        return res
