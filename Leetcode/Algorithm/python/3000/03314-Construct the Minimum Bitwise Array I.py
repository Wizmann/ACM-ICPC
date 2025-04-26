class Solution(object):
    def minBitwiseArray(self, nums):
        d = {}
        for i in xrange(1, 1234):
            x = i | (i + 1)
            if x not in d:
                d[x] = i
        res = []
        for num in nums:
            res.append(d.get(num, -1))
        return res
