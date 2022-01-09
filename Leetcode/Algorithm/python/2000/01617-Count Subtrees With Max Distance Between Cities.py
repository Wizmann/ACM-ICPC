from collections import defaultdict

class Solution(object):
    def countSubgraphsForEachDiameter(self, n, edges):
        self.g = defaultdict(list)
        for (a, b) in edges:
            a -= 1
            b -= 1
            self.g[a].append(b)
            self.g[b].append(a)
        res = [0 for i in xrange(n)]
        for i in xrange(1 << n):
            p = self.solve(i, n)
            if p > 0:
                res[p] += 1
        return res[1:]
    
    def solve(self, status, n):
        ps = []
        for i in xrange(n):
            if status & (1 << i):
                ps.append(i)
        if not ps:
            return -1
        reached, max_dis, _ = self.dfs(-1, ps[0], set(ps))
        if reached != len(ps):
            return -1
        return max_dis
    
    def dfs(self, pre, cur, ps):
        reached = 1
        max_dis = 0
        max_depth = 0
        ds = []
        for nxt in self.g[cur]:
            if nxt == pre:
                continue
            if nxt not in ps:
                continue
            r, dis, dep = self.dfs(cur, nxt, ps)
            reached += r
            max_depth = max(max_depth, dep + 1)
            max_dis = max(max_dis, dis)
            ds.append(dep)
        if len(ds) >= 2:
            ds.sort(reverse=True)
            max_dis = max(max_dis, ds[0] + ds[1] + 2)
        elif len(ds) == 1:
            max_dis = max(max_dis, ds[0] + 1)
        return reached, max_dis, max_depth
        
