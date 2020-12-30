class Solution(object):
    def zero(self, n):
        f, t = 0, 0
        
        for i in xrange(1, 32):
            f += n / (5 ** i)
            t += n / (2 ** i)
            
        return min(f, t)
        
    def preimageSizeFZF(self, K):
        l, r = 0, 10 ** 10
        while l <= r:
            m = (l + r) >> 1
            if self.zero(m) > K:
                r = m - 1
            else:
                l = m + 1
        RR = r
        
        l, r = 0, 10 ** 10
        while l <= r:
            m = (l + r) >> 1
            if self.zero(m) >= K:
                r = m - 1
            else:
                l = m + 1
        LL = r
        
        return RR - LL
