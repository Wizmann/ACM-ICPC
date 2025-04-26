class Solution(object):
    def findPeakGrid(self, mat):
        n = len(mat)
        m = len(mat[0])
        
        l, r = 0, m - 1
        while l < r:
            mid = (l + r) / 2
            llmax, rrmax = 0, 0
            for i in xrange(n):
                llmax = max(llmax, mat[i][mid])
            for i in xrange(n):
                rrmax = max(rrmax, mat[i][mid + 1])
                
            if llmax > rrmax:
                r = mid
            else:
                l = mid + 1
        maxi = -1
        maxp = -1
        for i in xrange(n):
            if mat[i][l] > maxi:
                maxi = mat[i][l]
                maxp = i
        return (maxp, l)
            
