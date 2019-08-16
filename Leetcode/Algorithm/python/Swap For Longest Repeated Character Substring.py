import string

class Solution(object):
    def maxRepOpt1(self, text):
        res = 0
        text += '$'
        for c in string.ascii_lowercase:
            res = max(res, self.solve(c, text))
        return res
    
    def solve(self, key, text):
        tot = text.count(key)
        cs = []
        l, r = -1, -1
        for i, c in enumerate(text):
            if c == key:
                if l == -1:
                    l, r = i, i
                else:
                    r = i
            else:
                if l != -1:
                    cs.append((l, r))
                    l, r = -1, -1
        m = len(cs)
        res = 0
        for i in xrange(m):
            (l, r) = cs[i]
            res = max(res, min(r - l + 1 + 1, tot))
            if i + 1 < m:
                (ll, rr) = cs[i + 1]
                #print cs[i], cs[i + 1]
                if ll == r + 2:
                    res = max(res, min(r - l + 1 + rr - ll + 1 + 1, tot))
        return res
            
        
