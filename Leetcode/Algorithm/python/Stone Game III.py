# https://leetcode.com/problems/stone-game-iii/

INF = 10 ** 10

class Solution(object):
    def stoneGameIII(self, stoneValue):
        self.d = {}
        res = self.dfs(0, stoneValue)
        if res > 0:
            return 'Alice'
        elif res == 0:
            return 'Tie'
        else:
            return 'Bob'
    
    def dfs(self, p, stones):
        n = len(stones)
        if p in self.d:
            return self.d[p]
        if p >= n:
            return 0
        res = -INF
        tot = 0
        for i in xrange(3):
            if p + i >= n:
                break
            tot += stones[p + i]
            res = max(res, tot - self.dfs(p + i + 1, stones))
        self.d[p] = res
        return res
        
        
