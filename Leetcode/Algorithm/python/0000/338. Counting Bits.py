class Solution(object):
    def countBits(self, num):
        res = [0 for i in xrange(num + 1)]
        for i in xrange(1, num + 1):
            res[i] = (i % 2) + res[i >> 1]
        return res
            
