class Solution(object):
    def checkZeroOnes(self, s):
        a = max(map(len, s.split('0')))
        b = max(map(len, s.split('1')))
        return a > b
