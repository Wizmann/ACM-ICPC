class Solution(object):
    def minFlips(self, s):
        u = s.count('0')
        v = max(0, s.count('1') - 1)
        w = s[1:-1].count('1')
        return min(u, v, w)
