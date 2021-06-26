import sys

sys.setrecursionlimit(10 ** 6)

MOD = (10 ** 9) + 7

class Solution(object):
    def rearrangeSticks(self, n, k):
        self.d = {}
        return self.dfs(n, k)
    
    def dfs(self, n, k):
        if n < 0:
            return 0
        if k < 0:
            return 0
        if n < k:
            return 0
        if n == k:
            return 1

        if (n, k) in self.d:
            return self.d[(n, k)]
        
        tot = 0
        tot += self.dfs(n - 1, k - 1)
        tot += (n - 1) * self.dfs(n - 1, k) % MOD
        tot %= MOD
        self.d[(n, k)] = tot
        return tot

