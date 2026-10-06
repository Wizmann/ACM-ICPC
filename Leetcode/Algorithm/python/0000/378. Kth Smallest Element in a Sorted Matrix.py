class Solution(object):
    def kthSmallest(self, matrix, k):
        if not matrix:
            return None
        n = len(matrix)
        if n == 0:
            return None
        m = len(matrix[0])
        if k > n * m:
            return None
        
        k = n * m - k
        
        for i in xrange(k + 1):
            maxi = -10 ** 10
            ptr = -1
            for j in xrange(n):
                if not matrix[j]:
                    continue
                cur = matrix[j][-1]
                if cur > maxi:
                    maxi = cur
                    ptr = j
            matrix[ptr].pop()
        return maxi
            
        
