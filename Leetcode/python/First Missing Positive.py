class Solution:
    # @param A, a list of integers
    # @return an integer
    def firstMissingPositive(self, A):
        n = len(A)
        for i in xrange(n):
            while A[i] - 1 != i:
                a = A[i]
                if a - 1 < 0 or a - 1 >= n or A[a - 1] == a:
                    break
                A[a - 1], A[i] = A[i], A[a - 1]
        for i, a in enumerate(A):
            if a != i + 1:
               return i + 1
        else:
            return n + 1
