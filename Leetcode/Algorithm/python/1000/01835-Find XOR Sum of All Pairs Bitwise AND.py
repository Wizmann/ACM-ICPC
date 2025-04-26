class Solution(object):
    def getXORSum(self, arr1, arr2):
        b1 = [0 for i in xrange(32)]
        b2 = [0 for i in xrange(32)]
        
        for num in arr1:
            for i in xrange(32):
                if num & (1 << i):
                    b1[i] += 1
        for num in arr2:
            for i in xrange(32):
                if num & (1 << i):
                    b2[i] += 1
                    
        res = 0
        for i in xrange(32):
            u = b1[i] * b2[i]
            res |= (u % 2) << i
        return res
