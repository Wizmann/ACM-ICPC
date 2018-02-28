class Solution:
    """
    @param nums: The number array
    @return: Return the single number
    """
    def getSingleNumber(self, nums):
        n = len(nums)
        l, r = 0, n - 1
        while l <= r:
            m = (l + r) >> 1
            if m - 1 >= 0 and nums[m] == nums[m - 1]:
                if (m - 1) % 2 != 0:
                    r = m - 2
                else:
                    l = m + 1
            elif m + 1 < n and nums[m + 1] == nums[m]:
                if m % 2 != 0:
                    r = m - 1
                else:
                    l = m + 2
            else:
                return nums[m]
        return nums[l]
