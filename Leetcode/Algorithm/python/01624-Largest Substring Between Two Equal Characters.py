from collections import defaultdict

class Solution(object):
    def maxLengthBetweenEqualCharacters(self, s):
        d = defaultdict(list)
        for i, c in enumerate(s):
            d[c].append(i)
            
        maxi = -1
        for k, vs in d.items():
            m = len(vs)
            maxi = max(maxi, vs[-1] - vs[0] - 1)
        return maxi
            
