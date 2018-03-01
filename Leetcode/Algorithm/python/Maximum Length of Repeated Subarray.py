class Solution(object):
    def findLength(self, A, B):
        return max(self.doFindLength(A, B), self.doFindLength(B, A))
    
    def doFindLength(self, A, B):
        n = len(A)
        m = len(B)
        res = 0
        for i in xrange(n):
            cur = 0
            ii = i
            j = 0
            while ii < n and j < m:
                if A[ii] != B[j]:
                    cur = 0
                else:
                    cur += 1
                    res = max(res, cur)
                ii += 1
                j += 1
        return res
