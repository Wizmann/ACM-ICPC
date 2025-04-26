class Solution(object):
    def maxA(self, n):
        self.d = {}
        return self.dfs(n)
        
    def dfs(self, n):
        if n == 1:
            return n
        if n in self.d:
            return self.d[n]
        
        ans = n
        for i in xrange(1, n - 3):
            ans = max(ans, self.dfs(i) * (n - i - 1))
        self.d[n] = ans
        return ans
