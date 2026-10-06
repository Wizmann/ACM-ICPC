class Solution(object):
    def canMakeEqual(self, nums, k):
        return self.solve(nums[:], k, 1) or self.solve(nums[:], k, -1)

    def solve(self, nums, k, value):
        n = len(nums)
        cnt = 0
        for i in xrange(n - 1):
            if nums[i] != value:
                cnt += 1
                nums[i] *= -1
                nums[i + 1] *= -1
            if cnt > k:
                return False
        return set(nums) == set([value])
