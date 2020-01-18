class Solution(object):
    def matrixBlockSum(self, mat, K):
        n = len(mat)
        m = len(mat[0])
        
        for i in xrange(n):
            for j in xrange(m):
                a = 0 if j - 1 < 0 else mat[i][j - 1]
                b = 0 if i - 1 < 0 else mat[i - 1][j]
                c = 0 if i - 1 < 0 or j - 1 < 0 else mat[i - 1][j - 1]
                mat[i][j] += a + b - c
                
        def getSubMatrix(y, x):
            if y < 0 or x < 0:
                return 0
            y = min(y, n - 1)
            x = min(x, m - 1)
            return mat[y][x]
                
        res = [[0 for j in xrange(m)] for i in xrange(n)]
        for i in xrange(n):
            for j in xrange(m):
                lx, ly = j - K, i - K
                rx, ry = j + K, i + K
                
                a = getSubMatrix(ry, rx)
                b = getSubMatrix(ry, lx - 1)
                c = getSubMatrix(ly - 1, rx)
                d = getSubMatrix(ly - 1, lx - 1)
                res[i][j] = a - b - c + d
        return res
                
                
