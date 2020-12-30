INF = 10 ** 10
my = [-1, 0, 1, 0]
mx = [0, 1, 0, -1]

class Solution(object):
    def minFlips(self, mat):
        self.d = {}
        self.n = len(mat)
        self.m = len(mat[0])
        
        cur = 0
        idx = 0
        for i in xrange(self.n):
            for j in xrange(self.m):
                cur += mat[i][j] * (1 << idx)
                #print i, j, mat[i][j], idx, cur
                idx += 1
                
        res = self.dfs(cur, 0)
        if res >= INF:
            return -1
        else:
            return res
    
    def dfs(self, cur, visited):
        #print cur, visited
        if cur in self.d:
            return self.d[cur]
        
        if cur == 0:
            return 0
        
        if visited == (1 << (self.n * self.m)) - 1:
            return INF
        
        res = INF
        for i in xrange(self.n * self.m):
            if visited & (1 << i):
                continue
            nxt = cur
            
            py = i / self.m
            px = i % self.m
            
            for j in xrange(4):
                ny = py + my[j]
                nx = px + mx[j]
                
                if ny < 0 or ny >= self.n or nx < 0 or nx >= self.m:
                    continue
                idx = ny * self.m + nx
                nxt ^= 1 << idx
            nxt ^= 1 << i
            
            res = min(res, self.dfs(nxt, visited | (1 << i)) + 1)
        self.d[cur] = res
        return res
            
            
            
