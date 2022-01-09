MOD = (10 ** 9) + 7

class Solution(object):
    def numOfArrays(self, n, m, k):
        self.d = {}
        return self.dfs(0, 0, n, m, k)
        
    def dfs(self, pre, cost, n, m, k):
        if cost > k or cost + (m - pre) < k:
            return 0
        if n == 0:
            return 1 if cost == k else 0
        key = (pre, cost, n)
        if key in self.d:
            return self.d[key]
        res = 0
        
        res += pre * self.dfs(pre, cost, n - 1, m, k)
        res %= MOD
        for i in xrange(pre + 1, m + 1):           
            res += self.dfs(i, cost + 1, n - 1, m, k)
            res %= MOD
        self.d[key] = res
        return res
            
        
