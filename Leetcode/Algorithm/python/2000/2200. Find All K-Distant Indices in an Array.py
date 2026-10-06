INF = 10 ** 10

class Solution(object):
    def findKDistantIndices(self, nums, key, k):
        n = len(nums)
        p, q1, q2 = 0, -INF, 0
        res = []
        while p < n:
            if p > q2:
                q1 = q2
                q2 = p
            while q2 < n and nums[q2] != key:
                q2 += 1
            if q2 == n:
                q2 = INF
                
            delta = min(abs(p - q1), abs(p - q2))
            if delta <= k:
                res.append(p)
            p += 1
        return res
                
