class Solution(object):
    def numDupDigitsAtMostN(self, N):
        self.d = {}
        self.number = map(int, str(N))
        ans = self.dfs(0, 0, False, False)
        return ans
    
    def dfs(self, status, cur, lt, dup):
        key = (status, cur, lt, dup)
        if key in self.d:
            return self.d[key]
        
        if cur == len(self.number):
            return 1 if dup and status > 1 else 0

        u = self.number[cur]
        ans = 0
        if lt and dup and status > 1:
            ans += 10 ** (len(self.number) - cur)
        else:
            for i in xrange(10):
                ss = status | (1 << i)
                if i == 0 and status == 0:
                    ss = 0
                    
                if lt or i < u:
                    g = True
                elif not lt and i == u:
                    g = False
                else:
                    continue
                
                if dup or (status & (1 << i)):
                    ans += self.dfs(ss, cur + 1, g, True)
                else:
                    ans += self.dfs(ss, cur + 1, g, False)

        self.d[key] = ans
        return ans
                        
            
