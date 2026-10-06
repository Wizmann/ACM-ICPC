from collections import defaultdict

INF = 10 ** 100

class UnionSet(object):
    def __init__(self):
        self.father = {}

    def add(self, a, b):
        fa = self.find_father(a)
        self.father[fa] = self.find_father(b)

    def find_father(self, a):
        if a not in self.father:
            self.father[a] = a
            return a
        if self.father[a] == a:
            return a
        fa = self.find_father(self.father[a])
        self.father[a] = fa
        return fa

    def is_same(self, a, b):
        return self.find_father(a) == self.find_father(b)

class Solution(object):
    def minCost(self, n, edges, k):
        us = UnionSet()
        edges.sort(key=lambda x: x[2])
        m = len(edges)
        self.g = defaultdict(list)
        cnt = 0
        for i in xrange(m):
            if cnt == n - k:
                break
            a, b, c = edges[i]
            if us.is_same(a, b):
                continue
            self.g[a].append((b, c))
            self.g[b].append((a, c))
            us.add(a, b)
            cnt += 1
        self.visited = set()
        res = 0
        for i in xrange(n):
            u = self.dfs(i)
            if u:
                res = max(res, u)
        return res

    def dfs(self, cur):
        if cur in self.visited:
            return 0
        self.visited.add(cur)
        res = 0
        for nxt, cost in self.g[cur]:
            res = max(res, self.dfs(nxt), cost)
        return res
