from collections import defaultdict

class Solution(object):
    def numEquivDominoPairs(self, dominoes):
        d = defaultdict(int)
        for (a, b) in dominoes:
            key = (min(a, b), max(a, b))
            d[key] += 1
            
        res = 0
        for key, value in d.items():
            res += value * (value - 1) / 2
        return res
        
