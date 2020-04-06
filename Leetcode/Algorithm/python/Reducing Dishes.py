# https://leetcode.com/problems/reducing-dishes/

class Solution:
    def maxSatisfaction(self, sat: List[int]) -> int:
        sat.sort()
        res = 0
        tot1 = 0
        tot2 = 0
        n = len(sat)
        for i in range(n):
            tot1 += sat[i]
            tot2 += (i + 1) * sat[i]
        res = max(res, tot2)
        while sat:
            top = sat.pop(0)
            tot1 -= top
            tot2 -= top + tot1
            res = max(res, tot2)
        return res
        
