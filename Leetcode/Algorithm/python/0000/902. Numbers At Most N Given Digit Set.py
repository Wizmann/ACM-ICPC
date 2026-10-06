class Solution(object):
    def atMostNGivenDigitSet(self, D, N):
        D = map(int, D)
        N = map(int, str(N))
        
        res = 0
        for i in xrange(1, len(N)):
            res += len(D) ** i
        res += self.dfs(N, D, 0, True)
        return res
    
    def dfs(self, N, D, cur, ub):
        if cur == len(N):
            return 1
        
        if ub == False:
            return len(D) ** (len(N) - cur)
        
        res = 0
        for d in D:
            if N[cur] == d:
                res += self.dfs(N, D, cur + 1, True)
            elif N[cur] > d:
                res += self.dfs(N, D, cur + 1, False)
        return res
