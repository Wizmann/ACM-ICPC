from collections import defaultdict

class Solution(object):
    def findReplaceString(self, S, indexes, sources, targets):
        n = len(S)
        m = len(indexes)
        d = defaultdict(list)
        
        for i in xrange(m):
            idx = indexes[i]
            s = sources[i]
            t = targets[i]
            d[idx].append((s, t))
        res = ''
        i = 0
        while i < n:
            for (s, t) in d[i]:
                if S[i:].startswith(s):
                    res += t
                    i += len(s)
                    break
            else:
                res += S[i]
                i += 1
        return res
        
