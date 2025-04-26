INF = 10 ** 10

class Solution(object):
    def countAlternatingSubarrays(self, nums):
        n = len(nums)
        p, q = 0, 0
        res = 0
        while p < n and q <= n:
            res += q - p
            if q < n:
                pre = -INF if p == q else nums[q - 1]
                cur = nums[q]
                if pre == cur:
                    p = q
            q += 1   
        return res             
                
