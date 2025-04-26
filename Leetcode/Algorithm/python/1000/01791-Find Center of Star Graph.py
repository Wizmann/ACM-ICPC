from collections import defaultdict

class Solution(object):
    def findCenter(self, edges):
        d = defaultdict(int)
        m = len(edges)
        for (a, b) in edges:
            d[a] += 1
            d[b] += 1
        for (key, value) in d.items():
            if value == m:
                return key
        return -1
