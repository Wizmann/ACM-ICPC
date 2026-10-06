from collections import defaultdict

class Solution(object):
    def countPairs(self, n, edges, queries):
        dd = defaultdict(int)
        pd = defaultdict(int)
        for (a, b) in edges:
            a, b = min(a, b), max(a, b)
            dd[a] += 1
            dd[b] += 1
            pd[(a, b)] += 1
        for i in xrange(1, n + 1):
            dd[i] = dd.get(i, 0)
        deg = sorted(dd.values())
        m = len(deg)
        res = []
        for q in queries:
            l, r = 0, m - 1
            tot = 0
            while l < r:
                if deg[l] + deg[r] <= q:
                    l += 1
                else:
                    tot += r - l
                    r -= 1
            for (a, b), c in pd.items():
                u = dd[a] + dd[b]
                if u > q and u - c <= q:
                    tot -= 1
            res.append(tot)
        return res
