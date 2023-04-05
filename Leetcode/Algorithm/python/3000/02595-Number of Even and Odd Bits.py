class Solution(object):
    def evenOddBit(self, n):
        even, odd = 0, 0
        for i in xrange(100):
            if i % 2 == 0:
                even += (1 if (n & (1 << i)) else 0)
            else:
                odd += (1 if (n & (1 << i)) else 0)
        return [even, odd]
