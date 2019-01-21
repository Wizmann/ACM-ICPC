INF = 10 ** 10

class Solution(object):
    def maxTurbulenceSize(self, A):
        return self.solve(A)
    
    def solve(self, A):
        l, r = 0, 2
        n = len(A)
        if n <= 1:
            return n
        res = 2
        while r < n:
            if (A[r - 2] > A[r - 1] < A[r]) or (A[r - 2] < A[r - 1] > A[r]):
                r += 1
            else:
                l += 1
                r = max(l + 2, r)
            res = max(res, r - l)
        return res
                
