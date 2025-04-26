class Solution(object):
    def findRotation(self, mat, target):
        n = len(mat)
        m = len(mat[0])
        assert n == m
        rotate0 = True
        rotate90 = True
        rotate180 = True
        rotate270 = True
        for i in xrange(n):
            for j in xrange(m):
                rotate0   &= mat[i][j] == target[i][j]
                rotate90  &= mat[i][j] == target[m - j - 1][i]
                rotate180 &= mat[i][j] == target[n - i - 1][m - j - 1]
                rotate270 &= mat[i][j] == target[j][n - i - 1]
        return any([rotate0, rotate90, rotate180, rotate270])
        
