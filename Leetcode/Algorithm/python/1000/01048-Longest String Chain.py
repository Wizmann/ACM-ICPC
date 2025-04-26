from collections import defaultdict

class Solution(object):
    def longestStrChain(self, words):
        self.d = defaultdict(list)
        n = len(words)
        
        words.sort(key=lambda w: len(w))
        
        for i in xrange(n):
            for j in xrange(i + 1, n):
                if self.check(words[i], words[j]):
                    self.d[i].append(j)
        ans = 0
        self.dp = [-1 for i in xrange(n)]
        for i in xrange(n):
            ans = max(ans, self.dfs(i))
        return ans
    
    def check(self, s, t):
        ls = len(s)
        lt = len(t)
        
        if ls + 1 != lt:
            return False

        p, q = 0, 0
        cnt = 0
        while p < ls and q < lt and cnt <= 1:
            if s[p] == t[q]:
                p += 1
                q += 1
            else:
                cnt += 1
                q += 1
        return p == ls
    
    def dfs(self, cur):
        if self.dp[cur] != -1:
            return self.dp[cur]
        
        res = 1
        for nxt in self.d[cur]:
            res = max(res, self.dfs(nxt) + 1)
        self.dp[cur] = res
        return res
