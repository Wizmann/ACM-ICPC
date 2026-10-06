class Solution(object):
    def search(self, nums, target):
        n = len(nums)
        l, r = 0, n - 1
        while l <= r:
            m = (l + r) >> 1
            if nums[m] >= target:
                r = m - 1
            else:
                l = m + 1
        return -1 if l < 0 or l >= n or nums[l] != target else l
