from collections import defaultdict

class Solution(object):
    def groupThePeople(self, groupSizes):
        n = len(groupSizes)
        d = defaultdict(list)
        
        for (i, g) in enumerate(groupSizes):
            d[g].append(i)
        
        res = []
        
        for size, ps in d.items():
            assert len(ps) % size == 0
            m = len(ps)
            for i in xrange(0, m, size):
                res.append(ps[i: i + size])
        return res
        
