class Solution(object):
    def minFallingPathSum(self, A):
        n = len(A)
        assert n > 0
        m = len(A[0])
        
        for i in xrange(1, n):
            for j in xrange(m):
                A[i][j] += min(A[i - 1][max(0, j - 1): min(m, j + 2)])
        return min(A[n - 1])
        
