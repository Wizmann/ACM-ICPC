from collections import defaultdict

class Solution(object):
    def beautifulSubstrings(self, s, k):
        n = len(s)
        res = 0
        vs = [0 for i in xrange(n)]
        cs = [0 for i in xrange(n)]
        for i in xrange(n):
            if s[i] in 'aeiou':
                vs[i] += 1
            else:
                cs[i] += 1
            if i:
                vs[i] += vs[i - 1]
                cs[i] += cs[i - 1]
        
        for i in xrange(1, n):
            v, c = 0, 0
            for j in xrange(i):
                v = vs[i] - (vs[j - 1] if j else 0)
                c = cs[i] - (cs[j - 1] if j else 0)
                if v == c and (v * c) % k == 0:
                    res += 1
        return res
