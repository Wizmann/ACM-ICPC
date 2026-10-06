from collections import defaultdict

class Solution(object):
    def maxSumDistinctTriplet(self, x, y):
        d = defaultdict(int)
        for (a, b) in zip(x, y):
            d[a] = max(d[a], b)
        if len(d) < 3:
            return -1
        return sum(sorted(d.values(), reverse=True)[:3])
