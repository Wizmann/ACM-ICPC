from collections import defaultdict

class Solution(object):
    def numberOfComponents(self, properties, k):
        n = len(properties)
        properties = map(set, properties)
        g = defaultdict(list)
        for i in xrange(n):
            for j in xrange(i + 1, n):
                if len(properties[i] & properties[j]) >= k:
                    g[i].append(j)
                    g[j].append(i)

        visited = set()
        cnt = 0
        for i in xrange(n):
            if i in visited:
                continue
            self.dfs(i, visited, g)
            cnt += 1
        return cnt

    def dfs(self, cur, visited, g):
        if cur in visited:
            return
        visited.add(cur)
        for nxt in g[cur]:
            self.dfs(nxt, visited, g)
