class Solution(object):
    def wordPatternMatch(self, pattern, s):
        self.d = {}
        self.p = set()
        return self.dfs(pattern, s)
    
    def dfs(self, pattern, s):
        if not pattern:
            return True if not s else False
        p = pattern[0]
        if p in self.d:
            q = self.d[p]
            if s.startswith(q):
                return self.dfs(pattern[1:], s[len(q):])
        else:
            n = len(s)
            for i in xrange(1, n + 1):
                sub = s[:i]
                if sub in self.p:
                    continue
                self.d[p] = sub
                self.p.add(sub)
                if self.dfs(pattern[1:], s[i:]):
                    return True
                del self.d[p]
                self.p.remove(sub)
            return False
            
