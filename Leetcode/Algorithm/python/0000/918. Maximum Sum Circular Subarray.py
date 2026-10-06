INF = 10 ** 10

class Solution(object):
    def maxSubarraySumCircular(self, A):
        if max(A) < 0:
            return max(A)
        return max(self.max_subarray(A), sum(A) - self.min_subarray(A))
    
    def max_subarray(self, A):
        res = -INF
        s = 0
        for a in A:
            s += a
            res = max(res, s)
            if s <= 0:
                s = 0
        return res
    
    def min_subarray(self, A):
        res = INF
        s = 0
        for a in A:
            s += a
            res = min(res, s)
            if s > 0:
                s = 0
        return res
