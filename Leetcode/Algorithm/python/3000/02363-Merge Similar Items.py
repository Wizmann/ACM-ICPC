from collections import defaultdict

class Solution(object):
    def mergeSimilarItems(self, items1, items2):
        d = defaultdict(int)
        for (v, w) in items1 + items2:
            d[v] += w
        return sorted(map(list, d.items()))
