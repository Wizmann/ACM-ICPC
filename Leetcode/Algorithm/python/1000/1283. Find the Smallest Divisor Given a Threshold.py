INF = 10 ** 10

class Solution(object):
    def smallestDivisor(self, nums, threshold):
        l, r = 1, INF
        
        while l <= r:
            m = (l + r) / 2
            
            tot = 0
            for num in nums:
                tot += (num + m - 1) / m
            if tot > threshold:
                l = m + 1
            else:
                r = m - 1
        return l
                
