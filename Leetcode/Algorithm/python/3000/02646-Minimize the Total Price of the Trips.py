class Solution(object):
    def minimumTotalPrice(self, n, edges, price, trips):
        self.n = n
        self.g = [ [] for i in xrange(n) ]
        self.price = price
        for (a, b) in edges:
            self.g[a].append(b)
            self.g[b].append(a)
            
        self.price2 = [0 for i in xrange(n)]
        self.dp = {}
        for (a, b) in trips:
            path = []
            self.dfs1(-1, a, b, path)
            print path
            for node in path:
                self.price2[node] += self.price[node]
                
        tot = sum(self.price2)
        # print tot
        tot -= self.dfs2(-1, 0, False)
        return tot
    
    def dfs1(self, pre, cur, dest, path):
        path.append(cur)
        if cur == dest:
            return True
        for nxt in self.g[cur]:
            if nxt == pre:
                continue
            if self.dfs1(cur, nxt, dest, path):
                return True
        path.pop()
        return False
      
    def dfs2(self, pre, cur, adj):
        key = (cur, adj)
        if key in self.dp:
            return self.dp[key]
        
        res = 0
        
        if not adj:
            u = self.price2[cur] / 2
            for nxt in self.g[cur]:
                if nxt == pre:
                    continue
                u += self.dfs2(cur, nxt, True)
            res = max(res, u)
            
        u = 0
        for nxt in self.g[cur]:
            if nxt == pre:
                continue
            u += self.dfs2(cur, nxt, False)
        res = max(res, u)
        
        self.dp[key] = res
        return res
            
        
