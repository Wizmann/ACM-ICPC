import copy

class Solution(object):
    def combinationSum3(self, k, n):
        self.tmp = []
        self.res = []
        self.dfs(n, k, 1)
        return self.res
        
    def dfs(self, n, k, p):
        if n == 0:
            if k != 0:
                return
            else:
                self.res.append(copy.deepcopy(self.tmp))
                return
        if k == 0:
            return
        if p > 9:
            return
        
        self.dfs(n, k, p + 1)
        self.tmp.append(p)
        self.dfs(n - p, k - 1, p + 1)
        self.tmp.pop()
    
        
