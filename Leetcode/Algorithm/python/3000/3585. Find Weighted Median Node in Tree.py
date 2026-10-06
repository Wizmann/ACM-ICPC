from collections import defaultdict, deque
import math

class Solution(object):
    def __init__(self):
        self.g = None
        self.N = 0
        self.LOG = 0
        self.up = None
        self.depth = None
        self.dist = None

    def findMedian(self, n, edges, queries):
        """
        n: nodes are 0..n-1, tree is rooted at 0
        edges: [(a,b,w)]
        queries: [(u,v)] -> returns weighted distance(u,v) for each
        """
        self.N = n
        self.g = defaultdict(list)
        for (a, b, w) in edges:
            self.g[a].append((b, w))
            self.g[b].append((a, w))

        self.LOG = int(math.ceil(math.log(max(2, n), 2))) + 1
        self.up = [[-1] * n for _ in xrange(self.LOG)]
        self.depth = [0] * n
        self.dist = [0] * n

        self._build(root=0)
        ans = []
        for (u, v) in queries:
            if u == v:
                ans.append(u)
                continue
            lca, d = self.LCA(u, v)
            print u, v, lca, d, self.dist[u], self.dist[lca]
            if (self.dist[u] - self.dist[lca]) * 2 >= d:
                acc = self._find_lowest_ancestor(u, d)
            else:
                acc = self._find_lowest_ancestor(v, d, True)
            ans.append(acc)

        return ans

    def _build(self, root):
        q = deque([root])
        self.up[0][root] = -1   # root has no parent
        self.depth[root] = 0
        self.dist[root] = 0

        seen = [False] * self.N
        seen[root] = True

        while q:
            v = q.popleft()
            for (to, w) in self.g[v]:
                if seen[to]:
                    continue
                seen[to] = True
                self.up[0][to] = v
                self.depth[to] = self.depth[v] + 1
                self.dist[to] = self.dist[v] + w
                q.append(to)

        for k in xrange(1, self.LOG):
            prev = self.up[k - 1]
            cur = self.up[k]
            for v in xrange(self.N):
                cur[v] = prev[prev[v]] if prev[v] != -1 else -1

    def _lift(self, v, steps):
        k = 0
        while steps and v != -1:
            if steps & 1:
                v = self.up[k][v]
            steps >>= 1
            k += 1
        return v

    def LCA(self, a, b):
        """
        Returns (lca_node, weighted_distance_between_original_a_b).
        """
        if a == b:
            return (a, 0)

        oa, ob = a, b  # keep originals for distance

        if self.depth[a] < self.depth[b]:
            a, b = b, a

        a = self._lift(a, self.depth[a] - self.depth[b])

        if a == b:
            lca = a
            d = self._dist_between(oa, ob, lca)
            return (lca, d)

        for k in xrange(self.LOG - 1, -1, -1):
            ua = self.up[k][a]
            ub = self.up[k][b]
            if ua != ub:
                a = ua
                b = ub

        lca = self.up[0][a]
        d = self._dist_between(oa, ob, lca)
        return (lca, d)

    def _dist_between(self, a, b, lca):
        return self.dist[a] + self.dist[b] - 2 * self.dist[lca]

    def _find_lowest_ancestor(self, node, d, lowerbound=False):
        cur = node
        for k in xrange(self.LOG - 1, -1, -1):
            anc = self.up[k][cur]
            if anc != -1:
                print node, anc, d, (self.dist[node] - self.dist[anc])
                if lowerbound:
                    if (d - (self.dist[node] - self.dist[anc])) * 2 > d:
                        cur = anc
                else:
                    if (self.dist[node] - self.dist[anc]) * 2 < d:
                        cur = anc
        if lowerbound:
            return cur
        return self.up[0][cur]

print Solution().findMedian(11, [[0,1,1000000000],[1,2,1000000000],[2,3,1000000000],[3,4,1000000000],[4,5,1000000000],[5,6,1000000000],[6,7,1000000000],[7,8,1000000000],[8,9,1000000000],[9,10,1000000000]], [[9, 0], [0, 9]])
