class Solution(object):
    def minDays(self, bloomDay, need, k):
        l, r = 0, max(bloomDay)
        while l <= r:
            m = (l + r) >> 1
            if self.check(bloomDay, m, k) >= need:
                r = m - 1
            else:
                l = m + 1
        if l > max(bloomDay):
            return -1
        return l
    
    def check(self, days, m, k):
        n = len(days)
        cnt = 0
        tot = 0
        for i in xrange(n):
            if days[i] <= m:
                cnt += 1
            else:
                cnt = 0
            if cnt >= k:
                tot += 1
                cnt = 0
        return tot
                
        
