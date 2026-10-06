class Solution(object):
    def winnerSquareGame(self, n):
        self.d = {0: False}
        return self.solve(n)
    
    def solve(self, n):
        if n in self.d:
            return self.d[n]
        u = 1
        flag = False
        while u * u <= n and not flag:
            if not self.solve(n - u * u):
                flag = True
            u += 1
        self.d[n] = flag
        return flag
