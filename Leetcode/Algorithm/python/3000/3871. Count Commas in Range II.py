class Solution(object):
    def countCommas(self, n):
        res = 0
        for i in xrange(1, 17):
            if n < (10 ** i):
                res += (n + 1 - (10 ** (i - 1))) * ((i - 1) / 3)
                break
            else:
                res += ((10 ** i) - (10 ** (i - 1))) * ((i - 1) / 3)

        return res
