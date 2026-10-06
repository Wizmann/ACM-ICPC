class Solution(object):
    def reverseDegree(self, s):
        tot = 0
        for i, c in enumerate(s):
            c = 26 - (ord(c) - ord('a'))
            tot += c * (i + 1)
        return tot
