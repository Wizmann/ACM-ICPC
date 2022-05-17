class Solution(object):
    def maxConsecutive(self, bottom, top, special):
        special.sort()
        cur = bottom
        
        p = 0
        res = 0
        while p < len(special):
            res = max(res, special[p] - cur)
            cur = special[p] + 1
            p += 1
        res = max(res, top - special[-1])
        return res
