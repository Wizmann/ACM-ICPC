class Solution(object):
    def maximumCandies(self, candies, k):
        l, r = 1, max(candies)
        
        while l <= r:
            m = (l + r) / 2
            if self.check(candies, k, m):
                l = m + 1
            else:
                r = m - 1
        return r
    
    def check(self, candies, k, m):
        cnt = 0
        for num in candies:
            cnt += num / m
            if cnt >= k:
                return True
        return False
        
        
