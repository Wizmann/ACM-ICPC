class Solution(object):
    def isArraySpecial(self, nums, queries):
        n = len(nums)
        nums2 = [0 for i in xrange(n)]
        for i in xrange(n - 1):
            nums2[i + 1] = (nums[i] % 2) ^ (nums[i + 1] % 2)
            nums2[i + 1] += nums2[i]
        # print nums2
        res = []
        for (l, r) in queries:
            sub = nums2[r] - nums2[l]
            res.append(sub == r - l)
        return res
