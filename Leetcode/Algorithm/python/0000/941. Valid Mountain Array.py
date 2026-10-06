class Solution(object):
    def validMountainArray(self, A):
        if len(A) < 3:
            return False
        n = len(A)
        
        flag = True
        for i in xrange(1, n):
            if (flag and A[i] > A[i - 1]) or (not flag and A[i] < A[i - 1]):
                continue
            elif i > 1 and flag and A[i] < A[i - 1]:
                flag = False
            else:
                return False
        return not flag
                
        
