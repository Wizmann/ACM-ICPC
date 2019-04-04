class Solution(object):
    def numEnclaves(self, A):
        self.n = len(A)
        self.m = len(A[0])
        
        for i in xrange(self.n):
            if A[i][0] == 1:
                self.dfs(A, i, 0)
            if A[i][self.m - 1] == 1:
                self.dfs(A, i, self.m - 1)
            
        for i in xrange(self.m):
            if A[0][i] == 1:
                self.dfs(A, 0, i)
            if A[self.n - 1][i] == 1:
                self.dfs(A, self.n - 1, i)
            
        res = 0
        for i in xrange(self.n):
            res += sum(A[i])
        return res
    
    def dfs(self, A, y, x):
        my = [-1, 0, 1, 0]
        mx = [0, 1, 0, -1]
        
        if A[y][x] == 1:
            A[y][x] = 0
            
        for i in xrange(4):
            ny = y + my[i]
            nx = x + mx[i]
            
            if 0 <= ny < self.n and 0 <= nx < self.m and A[ny][nx] == 1:
                self.dfs(A, ny, nx)
        
