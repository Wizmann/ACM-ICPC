class Solution(object):
    def makeStringsEqual(self, s, target):
        if '1' in s and '1' in target:
            return True
        return s == target
