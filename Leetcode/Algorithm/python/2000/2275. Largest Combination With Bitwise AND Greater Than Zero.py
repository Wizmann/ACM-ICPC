from collections import defaultdict

class Solution(object):
    def largestCombination(self, candidates):
        d = defaultdict(int)
        
        for num in candidates:
            for i in xrange(32):
                if num & (1 << i):
                    d[1 << i] += 1
        return max(d.values())
