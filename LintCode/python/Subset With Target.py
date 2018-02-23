class Solution:
    """
    @param nums: the array
    @param target: the target
    @return: the number of subsets which meet the following conditions
    """
    def subsetWithTarget(self, nums, target):
        nums.sort()
        n = len(nums)
        res = 0
        p, q = 0, n - 1
        while p <= q:
            if nums[p] + nums[q] >= target:
                q -= 1
            else:
                res += 1 << max(0, (q - p))
                p += 1
        return res
