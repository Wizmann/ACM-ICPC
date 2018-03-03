class Solution(object):
    def getFactors(self, n):
        if n == 1:
            return []
        self.res = []
        self.buffer = []
        self.dfs(n, 2)
        return self.res
        
    def dfs(self, n, pre):
        for i in xrange(pre, n / 2 + 1):
            if i * i > n:
                break
            if n % i == 0:
                self.buffer.append(i)
                self.res.append(self.buffer + [n / i])
                self.dfs(n / i, i)
                self.buffer.pop()
                
