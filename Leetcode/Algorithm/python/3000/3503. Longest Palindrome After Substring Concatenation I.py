class Solution(object):
    def longestPalindrome(self, s, t):
        n = len(s)
        m = len(t)
        maxi = 0
        for i1 in xrange(n):
            for i2 in xrange(i1 + 1, n + 1):
                s1 = s[i1: i2]
                if s1 == s1[::-1]:
                    maxi = max(maxi, len(s1))
                for j1 in xrange(m + 1):
                    for j2 in xrange(j1 + 1, m + 1):
                        t1 = t[j1: j2]
                        if t1 == t1[::-1]:
                            maxi = max(maxi, len(t1))
                        # print s1, t1
                        st = s1 + t1
                        if st == st[::-1]:
                            maxi = max(maxi, len(st))
        return maxi
