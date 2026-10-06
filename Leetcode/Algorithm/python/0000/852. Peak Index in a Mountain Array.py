class Solution(object):
    def peakIndexInMountainArray(self, A):
        n = len(A)
        l, r = 0, n - 1
        
        while l <= r:
            m1, m2 = (r - l) / 3 + l, r - (r - l) / 3
            v1, v2 = A[m1], A[m2]
            
            if v1 > v2:
                r = m2 - 1
            else:
                l = m1 + 1
        return r
