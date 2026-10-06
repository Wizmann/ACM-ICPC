class Solution(object):
    def findLUSlength(self, a, b):
        if len(a) != len(b):
            return max(len(a), len(b))
        elif a != b:
            return len(a)
        else:
            return -1
