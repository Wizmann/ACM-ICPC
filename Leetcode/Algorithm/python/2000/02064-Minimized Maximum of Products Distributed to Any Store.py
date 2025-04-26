class Solution(object):
    def minimizedMaximum(self, n, quantities):
        l, r = 1, max(quantities)
        
        while l <= r:
            m = (l + r) / 2
            if self.check(n, m, quantities):
                r = m - 1
            else:
                l = m + 1
        return l
    
    def check(self, n, m, quantities):
        cnt = 0
        for num in quantities:
            cnt += (num + m - 1) / m
        # print m, cnt
        return cnt <= n
