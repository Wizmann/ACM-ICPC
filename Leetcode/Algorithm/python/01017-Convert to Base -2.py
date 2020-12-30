class Solution(object):
    def baseNeg2(self, N):
        if N == 0:
            return '0'
        g = 1
        res = ''
        while N:
            if N % 2 == 1:
                res = '1' + res
                N -= g
                N /= 2
            else:
                res = '0' + res
                N /= 2
            g *= -1
        return res
