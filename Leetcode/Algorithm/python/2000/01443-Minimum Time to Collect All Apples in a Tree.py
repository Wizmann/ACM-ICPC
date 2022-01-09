from collections import defaultdict

class Solution(object):
    def minTime(self, n, edges, hasApple):
        self.d = defaultdict(list)
        for (a, b) in edges:
            self.d[a].append(b)
            self.d[b].append(a)
        self.apple = hasApple
        return self.dfs(-1, 0) * 2
    
    def dfs(self, pre, cur):
        res = 0
        # print '>>', pre, cur
        for nxt in self.d[cur]:
            if nxt == pre:
                continue
            res += self.dfs(cur, nxt)
        # print cur, res
        if res or self.apple[cur]:
            res += 1 if pre != -1 else 0
        return res
