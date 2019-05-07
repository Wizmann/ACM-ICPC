INF = 10 ** 10

class Solution(object):
    def numMovesStonesII(self, stones):
        stones.sort()
        self.n = len(stones)
        self.stones = stones
        
        return self.getMini(), self.getMaxi()
    
    def getMini(self):
        l, r = 0, 0
        mini = INF
        if self.stones[-1] - self.stones[0] + 1 == self.n:
            return 0
        while l < self.n and r < self.n:
            while l < self.n and r < self.n and self.stones[r] - self.stones[l] + 1 <= self.n:
                r += 1
            if r - l == self.n - 1 and self.stones[r - 1] - self.stones[l] + 1 == self.n - 1:
                mini = min(mini, self.n - (r - l) + 1)
            else:
                mini = min(mini, self.n - (r - l))
            l += 1
            r = min(r, self.n - 1)
        return mini
    
    def getMaxi(self):
        h = self.stones[-2] - self.stones[1] + 1 - (self.n - 2)
        return max(h + (self.stones[-1] - self.stones[-2] - 1), h + (self.stones[1] - self.stones[0] - 1))
