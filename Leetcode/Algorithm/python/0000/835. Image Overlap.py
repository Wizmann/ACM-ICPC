class Solution(object):
    def largestOverlap(self, A, B):
        pa = []
        pb = set()
        
        n = len(A)
        if n == 0:
            return 0
        m = len(A[0])
        
        for i in xrange(n):
            for j in xrange(m):
                if A[i][j] == 1:
                    pa.append((i, j))
                    
        for i in xrange(n):
            for j in xrange(m):
                if B[i][j] == 1:
                    pb.add((i, j))
                   
        maxi = 0
        for i in xrange(-30, 30 + 1):
            for j in xrange(-30, 30 + 1):
                sa = set(map(lambda (y, x): (y + i, x + j), pa))
                maxi = max(maxi, len(sa & pb))
        return maxi
