from collections import defaultdict, Counter

class Solution(object):
    def findMatrix(self, nums):
        d = defaultdict(list)
        c = Counter(nums)

        for key, value in c.items():
            for i in xrange(value):
                d[i].append(key)
        return d.values()
