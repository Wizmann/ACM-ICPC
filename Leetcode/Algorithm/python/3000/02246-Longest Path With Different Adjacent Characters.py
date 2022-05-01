from collections import defaultdict

class Solution(object):
    def longestPath(self, parent, s):
        self.d = defaultdict(list)
        for i, p in enumerate(parent):
            if p != -1:
                self.d[p].append(i)
        self.s = s
        self.ans = 0
        self.dfs(0)
        
        return self.ans
    
    def dfs(self, cur):
        children = [0]
        for nxt in self.d[cur]:
            c, l = self.dfs(nxt)
            if c != self.s[cur]:
                children.append(l)
        
        children.sort(reverse=True)
        self.ans = max(self.ans, sum(children[:2]) + 1)
        
        return self.s[cur], 1 + children[0]
