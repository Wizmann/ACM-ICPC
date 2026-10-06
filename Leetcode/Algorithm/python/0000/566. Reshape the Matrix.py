class Solution(object):
    def matrixReshape(self, nums, r, c):
        if not nums:
            return nums

        ns = sum(nums, [])
        if r * c > len(ns):
            return nums

        res = []
        for i in xrange(r):
            res.append(ns[c * i: c * (i + 1)])
        return res

print Solution().matrixReshape([[1,2], [3,4]], 1, 4)
print Solution().matrixReshape([[1,2], [3,4]], 2, 4)
print Solution().matrixReshape([[1,2], [3,4]], 4, 1)
