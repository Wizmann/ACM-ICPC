class Solution(object):
    def firstCompleteIndex(self, arr, mat):
        n = len(mat)
        m = len(mat[0])
        
        rows = [0 for i in xrange(n)]
        cols = [0 for i in xrange(m)]
        
        pos = [[] for i in xrange(n * m + 1)]
        for i in xrange(n):
            for j in xrange(m):
                v = mat[i][j]
                pos[v] = (i, j)
        for i, num in enumerate(arr):
            y, x = pos[num]
            rows[y] += 1
            cols[x] += 1
            
            if rows[y] == m or cols[x] == n:
                return i
        return -1
        
