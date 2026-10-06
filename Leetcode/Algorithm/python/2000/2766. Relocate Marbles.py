from collections import Counter

class Solution(object):
    def relocateMarbles(self, nums, moveFrom, moveTo):
        d = dict(Counter(nums))
        for a, b in zip(moveFrom, moveTo):
            d[a], d[b] = 0, d.get(b, 0) + d.get(a, 0)
        ps = []
        for key, value in d.items():
            if value:
                ps.append(key)
        return sorted(ps)
