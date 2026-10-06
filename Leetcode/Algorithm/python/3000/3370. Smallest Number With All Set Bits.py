class Solution(object):
    def smallestNumber(self, n):
        for i in xrange(123456789):
            if (1 << i) - 1 >= n:
                return (1 << i) - 1
        return -1
