from collections import defaultdict

MOD = 0xdeadbeefdeadbeef
PRIME = 128221

class Solution(object):
    def equalPairs(self, grid):
        d1 = defaultdict(int)
        d2 = defaultdict(int)
        
        n = len(grid)
        assert len(grid[0]) == n
        for i in xrange(n):
            cur = 0
            for j in xrange(n):
                cur = (cur * PRIME + grid[i][j]) % MOD
            d1[cur] += 1
            
        for j in xrange(n):
            cur = 0
            for i in xrange(n):
                cur = (cur * PRIME + grid[i][j]) % MOD
            d2[cur] += 1
            
        res = 0
        for (key, value) in d1.items():
            res += value * d2[key]
        return res
