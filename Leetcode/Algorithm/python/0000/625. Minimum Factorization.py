class Solution(object):
    def smallestFactorization(self, a):
        if a < 10:
            return a
        res = ""
        for i in xrange(9, 1, -1):
            while a % i == 0:
                res = str(i) + res
                a /= i
        if a != 1:
            return 0
        res = int(res)
        if res >= (1 << 31):
            res = 0
        return res
        
