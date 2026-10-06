from collections import defaultdict

class Solution(object):
    def numSubmatrixSumTarget(self, matrix, target):
        n = len(matrix)
        m = len(matrix[0])
        
        cnt = 0
        for i in xrange(m):
            for j in xrange(i, m):
                if i != j:
                    for k in xrange(n):
                        matrix[k][i] += matrix[k][j]
                d = defaultdict(int)
                d[0] += 1
                
                pre = 0
                for k in xrange(n):
                    pre += matrix[k][i]
                    key = pre - target 
                    if key in d:
                        #print i, j
                        cnt += d[key]
                    d[pre] += 1
        return cnt
