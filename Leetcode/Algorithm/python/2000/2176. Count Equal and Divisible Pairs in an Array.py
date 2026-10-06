class Solution(object):
    def countPairs(self, nums, k):
        n = len(nums)
        ans = 0
        for i in xrange(n):
            for j in xrange(i + 1, n):
                if nums[i] == nums[j] and (i * j) % k == 0:
                    ans += 1
        return ans
