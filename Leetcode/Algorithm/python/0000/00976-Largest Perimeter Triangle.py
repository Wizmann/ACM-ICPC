class Solution(object):
    def largestPerimeter(self, A):
        n = len(A)
        A.sort(reverse=True)
        ans = 0
        for i in xrange(n - 2):
            a, b, c= A[i], A[i + 1], A[i + 2]
            if b + c > a:
                ans = max(ans, a + b + c)
        return ans
