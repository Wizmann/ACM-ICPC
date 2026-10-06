class Solution(object):
    def isAdjacentDiffAtMostTwo(self, s):
        ns = map(int, s)
        n = len(ns)
        for i in xrange(n - 1):
            a, b = ns[i], ns[i + 1]
            if abs(a - b) > 2:
                return False
        return True
