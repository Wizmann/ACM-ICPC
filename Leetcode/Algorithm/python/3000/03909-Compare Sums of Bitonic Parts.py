class Solution(object):
    def compareBitonicSums(self, nums):
        peak = max(nums)
        peak_idx = nums.index(peak)
        n = len(nums)
        a = sum(nums[:peak_idx + 1])
        b = sum(nums[peak_idx:])
        if a > b:
            return 0
        elif a < b:
            return 1
        else:
            return -1
