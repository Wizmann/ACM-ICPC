from collections import defaultdict

INF = 10 ** 10

class Solution(object):
    def numSubmat(self, mat):
        n = len(mat)
        m = len(mat[0])
        dp = [ [0 for i in xrange(m)] for j in xrange(n) ]
        res = 0
        for i in xrange(m):
            for j in xrange(m - i):
                for k in xrange(n):
                    dp[k][j] += mat[k][i + j]
                pre = 0
                for k in xrange(n + 1):
                    if k == n or dp[k][j] != i + 1:
                        if pre == -1:
                            continue
                        u = k - pre
                        res += (1 + u) * u / 2
                        pre = -1
                    else:
                        if pre == -1:
                            pre = k
        return res
