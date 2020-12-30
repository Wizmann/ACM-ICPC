class Solution(object):
    def xorOperation(self, n, start):
        res = 0
        for i in xrange(n):
            res ^= start + i * 2
        return res
        
