INF = 10 ** 10
class Solution:
    def getMaxGridHappiness(self, m, n, ci, ce):
        self.d = {}
        self.m = m
        self.n = n
        return self.dfs('x' * n, ci, ce, 0)

    def dfs(self, prev, ni, ne, idx):
        key = (prev, ni, ne, idx)
        if key in self.d:
            return self.d[key]

        if ni < 0 or ne < 0:
            return -INF
        
        if idx >= self.m * self.n:
            return 0

        ans0 = self.dfs(prev[1:] + 'x', ni, ne, idx + 1)
        
        if idx % self.n == 0:
            ci = 1 * (prev[0] == 'i')
            ce = 1 * (prev[0] == 'e')
        else:
            ci = 1 * (prev[0] == 'i') + 1 * (prev[-1] == 'i')
            ce = 1 * (prev[0] == 'e') + 1 * (prev[-1] == 'e')
        
        ans1 = self.dfs(prev[1:] + 'i', ni - 1, ne, idx + 1) + 120 - 30 * (ci + ce) + 20 * ce - 30 * ci
        
        ans2 = self.dfs(prev[1:] + 'e', ni, ne - 1, idx + 1) + 40 + 20 * (ci + ce) + 20 * ce - 30 * ci
        
        # print(idx, ans0, ans1, ans2)
        
        self.d[key] = max(ans0, ans1, ans2)
        return self.d[key]
    

assert Solution().getMaxGridHappiness(2, 2, 4, 0) == 240
assert Solution().getMaxGridHappiness(3, 3, 2, 1) == 280
assert Solution().getMaxGridHappiness(3, 1, 1, 3) == 230
assert Solution().getMaxGridHappiness(2, 3, 1, 2) == 240
