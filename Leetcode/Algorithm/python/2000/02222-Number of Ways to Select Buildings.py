from collections import defaultdict
from copy import deepcopy

class Solution(object):
    def numberOfWays(self, s):
        d = defaultdict(int)
        n = len(s)
        s = map(int, s)
        
        # last, collected
        d[(0, 0)] = 1
        d[(1, 0)] = 1
        
        res = 0
        for i in xrange(n):
            dd = d.copy()
            cur = s[i]
            for j in xrange(0, 3):
                nxt = j + 1
                v = d.get((cur ^ 1, j), 0)
                # print i, cur, nxt, v
                if nxt == 3:
                    res += v
                elif v:
                    dd[(cur, nxt)] += v
            d = dd
        return res
