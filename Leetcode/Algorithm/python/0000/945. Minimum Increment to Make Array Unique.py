class Solution(object):
    def minIncrementForUnique(self, A):
        A.sort()
        n = len(A)
        res = 0
        for i in xrange(1, n):
            
            if A[i] < A[i - 1] + 1:
                res += A[i - 1] + 1 - A[i]
                A[i] = A[i - 1] + 1
  
        return res
