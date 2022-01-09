MOD = (10 ** 9) + 7

class Solution(object):
    def colorTheGrid(self, m, n):
        lines = []
        self.dfs(0, m, [], lines)
        u = len(lines)
        # print u
        g = [ [] for i in xrange(u) ]
        
        for i in xrange(u):
            for j in xrange(i + 1, u):
                for k in xrange(m):
                    if lines[i][k] == lines[j][k]:
                        break
                else:
                    g[i].append(j)
                    g[j].append(i)
        
        dp = [ [1 for i in xrange(u)], [0 for i in xrange(u)] ]
        
        p = 0
        for i in xrange(n - 1):
            q = p ^ 1
            dp[q] = [0 for i in xrange(u)]
            for j in xrange(u):
                for nxt in g[j]:
                    dp[q][nxt] += dp[p][j]
                    dp[q][nxt] %= MOD
            p = q
        return sum(dp[p]) % MOD
        
    def dfs(self, cur, m, buffer, lines):
        if cur == m:
            lines.append(buffer[:])
            return
        for i in xrange(3):
            if not buffer or buffer[-1] != i:
                buffer.append(i)
                self.dfs(cur + 1, m, buffer, lines)
                buffer.pop()
        
