class Solution(object):
    def ambiguousCoordinates(self, S):
        S = S[1: -1]
        n = len(S)
        res = []
        
        for i in xrange(n):
            l, r = S[:i], S[i:]
            p, q = len(l), len(r)
            for j in xrange(p + 1):
                if j == p:
                    ll = l
                else:
                    ll = "%s.%s" % (l[:j], l[j:])
                if not self.is_valid(ll):
                    continue
                    
                for k in xrange(q + 1):
                    if k == q:
                        rr = r
                    else:
                        rr = "%s.%s" % (r[:k], r[k:])
                    if not self.is_valid(rr):
                        continue
                    
                    res.append("(%s, %s)" % (ll, rr))
        return res

    def is_valid(self, s):
        if not s:
            return False
        if s.startswith('.') or s.endswith('.'):
            return False

        s = s.split('.')
        l, r = None, None
        
        if len(s) == 2:
            l, r = s
        else:
            l = s[0]

        if l != '0' and l.startswith('0'):
            return False
        
        if r and r.endswith('0'):
            return False
        
        return True
'''
S = Solution()
assert S.is_valid('1.00') == False
assert S.is_valid('.') == False
assert S.is_valid('1.') == False
assert S.is_valid('.1') == False
assert S.is_valid('00.1') == False
assert S.is_valid('0.0') == False
assert S.is_valid('0001') == False
assert S.is_valid('0.0001') == True
assert S.is_valid('0.00010') == False
assert S.is_valid('0') == True
'''     
