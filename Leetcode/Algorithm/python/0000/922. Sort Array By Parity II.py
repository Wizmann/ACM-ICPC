class Solution(object):
    def sortArrayByParityII(self, A):
        n = len(A)
        p, q = 0, 1
        while p < n and q < n:
            while p < n and A[p] % 2 == 0:
                p += 2
            while q < n and A[q] % 2 == 1:
                q += 2
            if p < n and q < n:
                A[p], A[q] = A[q], A[p]
        return A
