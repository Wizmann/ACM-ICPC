class Solution(object):
    def canThreePartsEqualSum(self, A):
        s = sum(A)
        n = len(A)
        if s % 3 != 0:
            return False
        p, q = 0, n - 1
        sp, sq = 0, 0
        while p < n and sp != s / 3:
            sp += A[p]
            p += 1
        while q >= 0 and sq != s / 3:
            sq += A[q]
            q -= 1
        return sp == sq == s / 3 and p <= q
