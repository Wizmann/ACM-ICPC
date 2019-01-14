from collections import defaultdict

class Solution(object):
    def subarraysDivByK(self, A, K):
        res = 0
        d = defaultdict(int)
        d[0] = 1
        s = 0
        for a in A:
            s += a
            s %= K
            if s in d:
                res += d[s]
            d[s] += 1
        return res
            
