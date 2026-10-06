from collections import defaultdict

class Solution(object):
    def edgeScore(self, edges):
        d = defaultdict(int)
        for i, value in enumerate(edges):
            d[value] += i
        return sorted(d.items(), key=lambda (i, v): (-v, i))[0][0]
