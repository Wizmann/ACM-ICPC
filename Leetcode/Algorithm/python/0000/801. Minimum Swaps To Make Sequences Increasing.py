INF = 10 ** 10

class Solution(object):
    def minSwap(self, A, B):
        a, b = 0, 0

        assert len(A) == len(B)
        n = len(A)

        for i in xrange(n):
            pa, pb = (-INF if i == 0 else A[i - 1]), (-INF if i == 0 else B[i - 1])
            na, nb = INF, INF
            if A[i] > pa and B[i] > pb:
                na = min(na, a)
                nb = min(nb, b + 1)
            if A[i] > pb and B[i] > pa:
                na = min(na, b)
                nb = min(nb, a + 1)
            a, b = na, nb
        return min(a, b)
        

assert Solution().minSwap([1, 3, 5, 4], [1, 2, 3, 7]) == 1
assert Solution().minSwap([1, 3, 5, 7], [1, 2, 3, 4]) == 0
assert Solution().minSwap([1], [2]) == 0
assert Solution().minSwap([1, 3], [2, 2]) == 1
