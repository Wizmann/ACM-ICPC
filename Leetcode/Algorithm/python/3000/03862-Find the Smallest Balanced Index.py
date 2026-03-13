class Solution(object):
    def smallestBalancedIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        l, r = 0, n - 1
        a, b = 0, 1
        MAXI = 10 ** 14

        while l < r:
            if a < b:
                a += nums[l]
                l += 1
            else:
                b *= nums[r]
                r -= 1
                b = min(MAXI, b)
            if l == r and a == b:
                return l
        return -1
