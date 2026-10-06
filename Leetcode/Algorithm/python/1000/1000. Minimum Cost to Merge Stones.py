INF = 10 ** 10

class Solution(object):
    def mergeStones(self, stones, K):
        self.dp = {}
        self.stones = stones
        self.k = K
        n = len(stones)
        if (n - 1) % (self.k - 1) != 0:
            return -1
        res = self.dfs(0, n, 1)
        #print self.dp
        return -1 if res >= INF else res
    
    def dfs(self, l, r, p):
        assert l != r
        key = (l, r, p)
        if key in self.dp:
            return self.dp[key]
        
        res = INF
        if r - l == 1:
            res = 0 if p == 1 else INF
        elif p == 1:
            res = sum(self.stones[l: r]) + self.dfs(l, r, self.k)
        else:
            for m in xrange(l + 1, r):
                res = min(res, self.dfs(l, m, p - 1) + self.dfs(m, r, 1))
            
        self.dp[key] = res        
        return res
