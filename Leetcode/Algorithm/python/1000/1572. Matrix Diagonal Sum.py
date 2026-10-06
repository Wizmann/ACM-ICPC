class Solution(object):
    def diagonalSum(self, mat):
        n = len(mat)
        res = 0
        for i in xrange(n):
            res += mat[i][i]
            mat[i][i] = 0
            res += mat[i][n - i - 1]
            mat[i][n - i - 1] = 0
        return res
            
