class Solution(object):
    def countQuadruplets(self, nums):
        n = len(nums)
        cnt = 0
        for a in xrange(n):
            for b in xrange(a + 1, n):
                for c in xrange(b + 1, n):
                    for d in xrange(c + 1, n):
                        if nums[a] + nums[b] + nums[c] == nums[d]:
                            cnt += 1
        return cnt
