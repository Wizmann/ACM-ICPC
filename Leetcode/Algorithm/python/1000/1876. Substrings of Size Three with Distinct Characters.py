class Solution(object):
    def countGoodSubstrings(self, s):
        n = len(s)
        cnt = 0
        for i in xrange(n - 2):
            ss = s[i: i + 3]
            if len(set(ss)) == 3:
                cnt += 1
        return cnt
