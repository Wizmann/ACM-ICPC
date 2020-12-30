from collections import defaultdict

class Solution(object):
    def numSubarraysWithSum(self, A, S):
        d = defaultdict(int)
        d[0] = 1
        res = 0
        pre = 0
        for i, a in enumerate(A):
            pre += a
            u = pre - S
            res += d[u]
            d[pre] += 1
        return res
            
        
