class Solution(object):
    def isMonotonic(self, A):
        return self.isInc(A) or self.isInc(A[::-1])
    
    def isInc(self, A):
        if not A:
            return False
        pre = A[0]
        for a in A:
            if a >= pre:
                pre = a
            else:
                return False
        return True
