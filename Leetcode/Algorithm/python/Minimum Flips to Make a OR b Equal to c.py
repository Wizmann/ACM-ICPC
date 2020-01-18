class Solution(object):
    def minFlips(self, a, b, c):
        res = 0
        for i in xrange(32):
            aa = a & (1 << i)
            bb = b & (1 << i)
            cc = c & (1 << i)
            print aa, bb, cc
            if cc == 0:
                res += 1 if aa else 0
                res += 1 if bb else 0
            elif cc and (aa | bb) == 0:
                res += 1
        return res
