INF = 10 ** 10
N = 101

class Solution(object):
    def minDifference(self, nums, queries):
        n = len(nums)
        presum = [ [0 for i in xrange(n)] for j in xrange(N)]
        
        for i, num in enumerate(nums):
            presum[num][i] += 1
        
        for i in xrange(N):
            for j in xrange(1, n):
                presum[i][j] += presum[i][j - 1]
                
        def range_count(v, l, r):
            lv = 0 if l == 0 else presum[v][l - 1]
            rv = presum[v][r]
            return rv - lv
        
        res = [INF for i in xrange(len(queries))]
        for idx, (l, r) in enumerate(queries):
            pre = -INF
            for i in xrange(N):
                c = range_count(i, l, r)
                if c == r - l + 1:
                    res[idx] = -1
                    break
                elif c:
                    res[idx] = min(res[idx], i - pre)
                    pre = i
        return res
                
