INF = 10 ** 10

class Solution(object):
    def constrainedSubsetSum(self, nums, k):
        res = -INF
        q = []
        for i, num in enumerate(nums):
            # q[0][0] is for pos
            # q[0][1] is for sum
            while q and i - q[0][0] > k:
                (p, v) = q.pop(0)
            pre = 0
            if q:
                pre = max(pre, q[0][1])
            while q and q[-1][1] <= pre + num:
                (p, v) = q.pop()
            q.append((i, pre + num))
            res = max(res, pre + num)
            # print q
        return res
            
                
            
            
        
