class Solution(object):
    def fairCandySwap(self, A, B):
        diff = sum(A) - sum(B)
        assert diff % 2 == 0
        B = set(B)
        for a in A:
            c = a - diff / 2
            if c in B:
                return (a, c)
        return (-1, -1)
