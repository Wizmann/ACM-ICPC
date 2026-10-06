class Solution(object):
    def areSimilar(self, mat, k):
        n = len(mat)
        m = len(mat[0])
        k %= m

        for i in xrange(n):
            if i % 2 == 0:
                p, q = 0, k % m
            else:
                p, q = 0, (m - k) % m
            for j in xrange(m):
                if mat[i][p] == mat[i][q]:
                    p = (p + 1) % m
                    q = (q + 1) % m
                else:
                    return False
        return True
