class Solution:
    """
    @param: nums: n non-negative integer array
    @return: A string
    """
    def minNumber(self, nums):
        return str(int(''.join(map(str, sorted(nums, cmp=lambda x, y: cmp(int(str(x) + str(y)), int(str(y) + str(x))))))))
