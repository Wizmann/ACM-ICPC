from collections import defaultdict

class Solution(object):
    def anagramMappings(self, A, B):
        n = len(A)
        d = defaultdict(list)
        for i, b in enumerate(B):
            d[b].append(i)
        
        res = [0 for i in xrange(n)]
        for i, a in enumerate(A):
            res[i] = d[a].pop()
        return res
