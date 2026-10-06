class Solution(object):
    def maximumRemovals(self, s, p, removable):
        l, r = 0, len(removable)
        while l <= r:
            m = (l + r) / 2
            if self.issubstr(s, p, removable[:m]):
                l = m + 1
            else:
                r = m - 1
        return r
        
    def issubstr(self, a, b, removed):
        st = set(removed)
        
        n = len(a)
        m = len(b)
        p, q = 0, 0
        while p < n and q < m:
            while p in st:
                p += 1
            if p >= n:
                break
            if a[p] == b[q]:
                p += 1
                q += 1
            else:
                p += 1
        return q == m
        
