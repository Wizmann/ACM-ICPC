INF = 10 ** 10

class Solution(object):
    def smallestRangeII(self, A, K):
        n = len(A)
        A.sort()
        res = A[-1] - A[0]
        for i in xrange(1, n):
            mini = min(A[0] + K, A[i] - K)
            maxi = max(A[i - 1] + K, A[-1] - K)
            res = min(res, maxi - mini)
        return res
