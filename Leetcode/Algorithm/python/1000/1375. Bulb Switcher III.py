# https://leetcode.com/problems/bulb-switcher-iii

class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        n = len(light)
        ns = [0 for i in range(n)]
        p = 0
        res = 0
        for i, l in enumerate(light):
            ns[l - 1] = 1
            flag = False
            while p < n and ns[p] == 1:
                p += 1
            if p == i + 1:
                res += 1
        return res
