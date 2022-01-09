from itertools import groupby

class Solution(object):
    def countBinarySubstrings(self, s):
        l = [len(list(g)) for k, g in groupby(s)]
        n = len(l)
        ans = 0
        for i in xrange(n - 1):
            ans += min(l[i], l[i + 1])
        return ans
