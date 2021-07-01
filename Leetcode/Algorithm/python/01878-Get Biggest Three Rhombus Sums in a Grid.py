from copy import deepcopy

INF = 10 ** 10

class Solution(object):
    def getBiggestThree(self, grid):
        n = len(grid)
        m = len(grid[0])
        A = deepcopy(grid)
        B = deepcopy(grid)
        
        for i in xrange(n):
            for j in xrange(m):
                if i - 1 >= 0 and j - 1 >= 0:
                    A[i][j] += A[i - 1][j - 1]
        
        for i in xrange(n):
            for j in xrange(m - 1, -1, -1):
                if i - 1 >= 0 and j + 1 < m:
                    B[i][j] += B[i - 1][j + 1]
                    
        def presumA(y1, x1, y2, x2):
            if y1 < 0 or x1 < 0 or y1 >= n or x1 >= m:
                return -INF
            if y2 < 0 or x1 < 0 or y2 >= n or x2 >= m:
                return -INF
            a = 0
            if y1 - 1 >= 0 and x1 - 1 >= 0:
                a = A[y1 - 1][x1 - 1]
            return A[y2][x2] - a
        
        def presumB(y1, x1, y2, x2):
            if y1 < 0 or x1 < 0 or y1 >= n or x1 >= m:
                return -INF
            if y2 < 0 or x1 < 0 or y2 >= n or x2 >= m:
                return -INF
            a = 0
            if y1 - 1 >= 0 and x1 + 1 < m:
                a = B[y1 - 1][x1 + 1]
            return B[y2][x2] - a

        res = []
        for i in xrange(n):
            for j in xrange(m):
                res.append(grid[i][j])
        for i in xrange(n):
            for j in xrange(m):
                for k in xrange(1, max(n, m)):
                    tot = 0
                    tot += presumA(i, j, i + k, j + k)
                    tot += presumA(i - k, j + k, i, j + k + k)
                    tot += presumB(i - k, j + k, i, j)
                    tot += presumB(i, j + k + k, i + k, j + k)
                    
                    if tot < 0:
                        continue
                    tot -= grid[i][j] + grid[i + k][j + k] + grid[i - k][j + k] + grid[i][j + k + k]
                    res.append(tot)
        return sorted(set(res), reverse=True)[:3]
