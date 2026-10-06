INF = 10 ** 10

class Solution(object):
    def lexicographicallySmallestArray(self, nums, limit):
        n = len(nums)
        nums = sorted(zip(nums, range(n))) + [(INF, INF)]
        res = [-INF for i in xrange(n)]
        pos, val = [], []
        for (num, idx) in nums:
            if val and abs(num - val[-1]) > limit:
                pos.sort()
                val.sort()
                for p, v in zip(pos, val):
                    res[p] = v
                pos, val = [], []
            pos.append(idx)
            val.append(num)
        return res

        
            
            
