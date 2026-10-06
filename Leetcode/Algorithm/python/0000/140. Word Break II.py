class Solution(object):
    def wordBreak(self, s, wordDict):
        self.st = set(wordDict)
        self.s = s
        self.n = len(s)
        self.res = []
        self.dp = [None for i in xrange(self.n)]
        
        return self.dfs(0)
        
    def dfs(self, cur):
        if cur == self.n:
            return [""]
        if self.dp[cur] is not None:
            return self.dp[cur]
        res = []
        for j in xrange(cur + 1, self.n + 1):
            if self.s[cur: j] in self.st:
                res += map(lambda x: self.s[cur: j] + " " + x, self.dfs(j))
        self.dp[cur] = map(lambda x: x.strip(), res)
        return self.dp[cur]
        
        
