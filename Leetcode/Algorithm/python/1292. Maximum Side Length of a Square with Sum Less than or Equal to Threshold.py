from copy import deepcopy

class Solution(object):
    def maxSideLength(self, mat, threshold):
        n = len(mat)
        m = len(mat[0])
        
        linePrefix = deepcopy(mat)
        colPrefix = deepcopy(mat)
        
        for i in xrange(n):
            for j in xrange(m):
                linePrefix[i][j] += 0 if j - 1 < 0 else linePrefix[i][j - 1]
        
        for j in xrange(m):
            for i in xrange(n):
                colPrefix[i][j] += 0 if i - 1 < 0 else colPrefix[i - 1][j]
                
        def lineSum(l, a, b):
            return linePrefix[l][b] - (0 if a - 1 < 0 else linePrefix[l][a - 1])
        def colSum(c, a, b):
            return colPrefix[b][c]  - (0 if a - 1 < 0 else colPrefix[a - 1][c])
        
        sp = []
        for i in xrange(n):
            sp.append((i, 0))
        for j in xrange(m):
            sp.append((0, j))
            
        res = 0
        for (y, x) in sp:
            tot = 0
            k = 1
            for i in xrange(min(n, m)):
                cy = y + i
                cx = x + i
                if cy >= n or cx >= m:
                    break
                tot += lineSum(cy, cx - k + 1, cx) + colSum(cx, cy - k + 1, cy) - mat[cy][cx]
                while tot > threshold:
                    tot -= lineSum(cy - k + 1, cx - k + 1, cx) + colSum(cx - k + 1, cy - k + 1, cy) - mat[cy - k + 1][cx - k + 1]
                    k -= 1
                res = max(res, k)
                k += 1
        return res
                
                    
                    
