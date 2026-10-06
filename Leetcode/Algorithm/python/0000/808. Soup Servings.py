import sys   
sys.setrecursionlimit(10000000)

class Solution(object):
    def soupServings(self, N):
        self.d = {}
        if N > 10000:
            return 1
        return self.solve(N, N)
    
    def solve(self, a, b):
        if (a, b) in self.d:
            return self.d[(a, b)]
        
        if a <= 0 and b <= 0:
            return 0.5
        
        if b <= 0:
            return 0
        
        if a <= 0:
            return 1
        
        c = 0.25 * self.solve(a - 100, b) + \
               0.25 * self.solve(a - 75, b - 25) + \
               0.25 * self.solve(a - 50, b - 50) + \
               0.25 * self.solve(a - 25, b - 75)
        
        self.d[(a, b)] = c
        return c
        
        
