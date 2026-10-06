N = 101

class Solution(object):
    def smallestTrimmedNumbers(self, nums, queries):
        ms = [ [] for i in xrange(N) ]
        for i in xrange(1, N):
            for j, num in enumerate(nums):
                item = (num[-i:], j)
                ms[i].append(item)
            ms[i].sort()
        # print ms[1]
        res = []
        for (a, b) in queries:
            res.append(ms[b][a - 1][1])
        return res
            
            
