from collections import Counter

class Solution(object):
    def minCostToMoveChips(self, chips):
        c = Counter(chips)
        mini = 10 ** 10
        for (k1, v1) in c.items():
            tot = 0
            for (k2, v2) in c.items():
                tot += (abs(k2 - k1) % 2) * v2
            mini = min(tot, mini)
        return mini
