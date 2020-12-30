class Solution(object):
    def findMin(self, nums):
        n = len(nums)
        if n < 3:
            return min(nums)
        l, r = 0, n - 1
        while l <= r:
            m = (l + r) >> 1
            a, b, c = nums[l], nums[m], nums[r]
            if b > a > c:
                l = m
            elif b < c < a:
                r = m
            else:
                return min(a, b, c)
        return l
