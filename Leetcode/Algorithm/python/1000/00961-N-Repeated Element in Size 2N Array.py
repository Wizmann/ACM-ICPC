class Solution(object):
    def repeatedNTimes(self, A):
        n = len(A)
        A.sort()
        if A[0] == A[n / 2 - 1]:
            return A[0]
        elif A[n / 2] == A[-1]:
            return A[-1]
        else:
            return A[n / 2 - 1]
