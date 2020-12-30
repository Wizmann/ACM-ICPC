class Solution(object):
    def smallestRangeI(self, A, K):
        A.sort()
        a, b = A[0], A[-1]
        return max(0, b - a - 2 * K)
