class Solution(object):
    def maxDistinct(self, s):
        st = set(s)
        return len(st)
