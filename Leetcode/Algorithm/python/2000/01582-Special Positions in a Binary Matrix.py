class Solution(object):
    def numSpecial(self, mat):
        n = len(mat)
        m = len(mat[0])

        ys = []
        for i in xrange(n):
            ys.append(sum(mat[i]))

        xs = []
        for j in xrange(m):
            tot = 0
            for i in xrange(n):
                tot += mat[i][j]
            xs.append(tot)

        res = 0
        for i in xrange(n):
            for j in xrange(m):
                if mat[i][j] == 1 and ys[i] == 1 and xs[j] == 1:
                    res += 1
        return res

mat1 = [[0,0,0,1],
        [1,0,0,0],
        [0,1,1,0],
        [0,0,0,0]]
assert Solution().numSpecial(mat1) == 2

