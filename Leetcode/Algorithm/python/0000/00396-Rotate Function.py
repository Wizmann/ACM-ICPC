class Solution(object):
    def maxRotateFunction(self, A):
        if not A:
            return 0
        s = sum(A)
        n = len(A)
        v = 0
        ans = -(10 ** 10)
        for i in xrange(n):
            v += A[i] * i
        for item in A[::-1]:
            ans = max(ans, v)
            v += s
            v -= item * n
        return ans
