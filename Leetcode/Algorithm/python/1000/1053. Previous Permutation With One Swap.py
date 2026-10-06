class Solution(object):
    def prevPermOpt1(self, A):
        n = len(A)
        idx = -1
        for i in xrange(n - 2, -1, -1):
            if A[i] > A[i + 1]:
                idx = i
                break
        else:
            return A
        
        pivot = A[idx]
        maxi = -1
        maxp = -1
        for i in xrange(idx + 1, n):
            if A[i] >= pivot:
                continue
            if A[i] > maxi:
                maxi = A[i]
                maxp = i
        A[idx], A[maxp] = A[maxp], A[idx]
        return A
