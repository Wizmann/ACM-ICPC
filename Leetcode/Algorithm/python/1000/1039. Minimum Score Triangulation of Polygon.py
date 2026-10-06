class Solution(object):
    def minScoreTriangulation(self, A):
        self.A = A
        n = len(A)
        self.n = n
        self.d = {}
        return self.dfs(0, n - 1)
    
    def dfs(self, l, r):
        key = (l, r)
        if key in self.d:
            return self.d[key]
        
        cnt = 0
        m = r - l + 1
        if m <= 0:
            m += self.n
        if m < 3:
            return 0
        else:
            ptr = l
            mini = 10 ** 10
            while True:
                ptr = (ptr + 1) % self.n
                if ptr == r:
                    break
                a, b, c = l, ptr, r
                mini = min(mini, self.dfs(l, ptr) + self.dfs(ptr, r) + self.A[a] * self.A[b] * self.A[c])
            self.d[key] = mini
            return mini
