class Solution(object):
    def findIndices(self, nums, indexDifference, valueDifference):
        n = len(nums)
        for i in xrange(n):
            for j in xrange(i + indexDifference, n):
                if abs(nums[i] - nums[j]) >= valueDifference:
                    return [i, j]
        return [-1, -1]
