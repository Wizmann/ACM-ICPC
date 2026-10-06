class Solution(object):
    def restoreMatrix(self, rowSum, colSum):
        n = len(rowSum)
        m = len(colSum)
        res = [[0 for j in xrange(m)] for i in xrange(n)]
        for i in xrange(n):
            for j in xrange(m):
                res[i][j] = min(rowSum[i], colSum[j])
                rowSum[i] -= res[i][j]
                colSum[j] -= res[i][j]
        return res
