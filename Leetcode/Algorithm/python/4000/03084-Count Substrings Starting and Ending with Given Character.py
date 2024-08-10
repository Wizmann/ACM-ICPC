class Solution(object):
    def countSubstrings(self, s, c):
        m = s.count(c)
        return m * (m - 1) / 2 + m
