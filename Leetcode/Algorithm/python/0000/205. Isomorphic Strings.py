class Solution(object):
    def isIsomorphic(self, s, t):
        d1, d2 = {}, {}
        n = len(s)
        for i in xrange(n):
            a, b = s[i], t[i]
            if a not in d1 and b not in d2:
                d1[a] = b
                d2[b] = a
            elif a in d1 and b in d2 and d1[a] == b and d2[b] == a:
                pass
            else:
                return False
        return True
