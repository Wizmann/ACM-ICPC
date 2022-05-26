class Solution(object):
    def minBitFlips(self, start, goal):
        return '{:b}'.format(start ^ goal).count('1')
