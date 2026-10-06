class Solution(object):
    def separateSquares(self, squares):
        l, r = 0, 1e10
        while abs(l - r) > 1e-5:
            m = (l + r) / 2
            A1, A2 = 0, 0
            for (a, b, c) in squares:
                if b + c < m:
                    A1 += c * c
                elif b > m:
                    A2 += c * c
                else:
                    A1 += c * (m - b)
                    A2 += c * (b + c - m)
            # print m, A1, A2
            if A1 < A2:
                l = m
            else:
                r = m
        return l
