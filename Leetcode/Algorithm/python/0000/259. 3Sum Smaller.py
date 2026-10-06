class Solution(object):
    def threeSumSmaller(self, nums, target):
        n = len(nums)
        if n < 3:
            return 0
        nums.sort()
        res = 0
        for i in xrange(n):
            a = nums[i]
            p, q = i + 1, n - 1
            while p < q:
                b, c = nums[p], nums[q]
                if a + b + c >= target:
                    q -= 1
                else:
                    res += q - p
                    p += 1
        return res
