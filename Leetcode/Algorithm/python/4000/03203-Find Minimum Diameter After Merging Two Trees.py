from collections import defaultdict

class Solution(object):
    def minimumDiameterAfterMerge(self, edges1, edges2):
        a = self.solve(edges1) + self.solve(edges2) + 1
        b = self.get_diameter(edges1)
        c = self.get_diameter(edges2)
        return max(a, b, c)
    
    def solve(self, edges):
        g = defaultdict(list)
        for (a, b) in edges:
            g[a].append(b)
            g[b].append(a)

        depth = {}
        self.dfs1(g, -1, 0, depth)
        return self.dfs2(g, depth, -1, 0, 0)

    def get_diameter(self, edges):
        g = defaultdict(list)
        for (a, b) in edges:
            g[a].append(b)
            g[b].append(a)

        p, _ = self.dfs0(g, -1, 0)
        _, d = self.dfs0(g, -1, p)
        return d

    def dfs0(self, g, pre, cur):
        d = 0
        p = cur
        for nxt in g[cur]:
            if nxt == pre:
                continue
            pp, dd = self.dfs0(g, cur, nxt)
            if dd + 1 > d:
                p = pp
                d = dd + 1
        return p, d

    def dfs1(self, g, pre, cur, depth):
        maxi = 0
        for nxt in g[cur]:
            if nxt == pre:
                continue
            maxi = max(maxi, self.dfs1(g, cur, nxt, depth) + 1)
        depth[cur] = maxi
        return maxi

    def dfs2(self, g, depth, pre, cur, head):
        mini = max(head, depth[cur])
        nxtdepth = []
        for nxt in g[cur]:
            if nxt == pre:
                continue
            nxtdepth.append(depth[nxt])
        nxtdepth.append(-1)
        nxtdepth.sort(reverse=True)

        for nxt in g[cur]:
            if nxt == pre:
                continue
            nxthead = head
            if nxtdepth[0] == depth[nxt]:
                nxthead = max(nxthead, nxtdepth[1] + 1)
            else:
                nxthead = max(nxthead, nxtdepth[0] + 1)
            # print '>>', head, nxtdepth, nxthead, g[cur]
            mini = min(mini, self.dfs2(g, depth, cur, nxt, nxthead + 1))
        # print '>>', cur, mini
        return mini
