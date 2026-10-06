MOD = (10 ** 9) + 7

n = (10 ** 5) + 123
factorial = [1]

for i in xrange(1, n):
    factorial.append(factorial[i - 1] * i % MOD)

inv = [1]
for i in xrange(1, n):
    inv.append(pow(factorial[i], MOD - 2, MOD))
    
def C(a, b):
    return factorial[b] * inv[b - a] * inv[a]

class Solution(object):
    def waysToBuildRooms(self, prevRoom):
        n = len(prevRoom)
        self.g = [[] for i in xrange(n)]
        self.sizes = [0 for i in xrange(n)]
        for i, prev in enumerate(prevRoom):
            if i == 0:
                continue
            self.g[prev].append(i)
            
        self.dfs1(0)
        return self.dfs2(0)
        
    def dfs1(self, cur):
        size = 1
        for nxt in self.g[cur]:
            size += self.dfs1(nxt)
        self.sizes[cur] = size
        return size
    
    def dfs2(self, cur):
        res = 1
        rem = self.sizes[cur] - 1
        for nxt in self.g[cur]:
            res *= self.dfs2(nxt)
            res *= C(self.sizes[nxt], rem)
            res %= MOD
            rem -= self.sizes[nxt]
        return res
