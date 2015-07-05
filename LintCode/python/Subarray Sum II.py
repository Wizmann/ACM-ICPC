class Solution:
    # @param {int[]} A an integer array
    # @param {int} start an integer
    # @param {int} end an integer
    # @return {int} the number of possible answer
    def subarraySumII(self, A, start, end):
        A = [0] + A
        n = len(A)
        for i in xrange(1, n):
            A[i] += A[i - 1]
        a = self.solve(A, lambda x: x >= start)
        b = self.solve(A, lambda x: x > end)
        return a - b
    
    def solve(self, A, fun):
        n = len(A)
        ans = 0
        p, q = 0, 1
        while p < n and q < n:
            while q < n and not fun(A[q] - A[p]):
                q += 1
            ans += n - q
            p += 1
        return ans
