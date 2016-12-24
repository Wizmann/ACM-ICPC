class Solution(object):
    def hammingDistance(self, x, y):
        z = x ^ y
        return '{:b}'.format(z).count('1')
