class Solution(object):
    def countFairPairs(self, nums, lower, upper):
        nums.sort()
        n = len(nums)
        tot = 0
        p1, p2 = n - 1, n - 1
        # print nums
        for i in xrange(n):
            p1 = min(n - 1, max(p1, i + 1))
            while p1 > i and nums[i] + nums[p1] >= lower:
                p1 -= 1
            while p2 > i and nums[i] + nums[p2] > upper:
                p2 -= 1
            # print i, p1, p2
            if p2 > p1:
                tot += p2 - p1
        return tot
