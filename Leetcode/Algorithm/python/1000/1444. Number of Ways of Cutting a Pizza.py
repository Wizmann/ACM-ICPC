from collections import defaultdict
import copy
MOD = (10 ** 9) + 7

class Solution(object):
    def ways(self, pizza, k):
        d = defaultdict(int)
        n = len(pizza)
        m = len(pizza[0])
        
        psum = [ [0 for j in xrange(m + 1)] for i in xrange(n + 1) ]
        
        for i in xrange(n):
            for j in xrange(m):
                if pizza[i][j] == 'A':
                    psum[i + 1][j + 1] = 1
        
        for i in xrange(1, n + 1):
            for j in xrange(1, m + 1):
                psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1]
        
        def msum(y1, x1, y2, x2):
            return psum[y2][x2] + psum[y1 - 1][x1 - 1] - psum[y2][x1 - 1] - psum[y1 - 1][x2]
        
        dp = [defaultdict(int) for i in xrange(k)]
        for y1 in xrange(1, n + 1):
            if msum(1, 1, y1, m):
                dp[0][(y1 + 1, 1)] = 1
        for x1 in xrange(1, m + 1):
            if msum(1, 1, n, x1):
                dp[0][(1, x1 + 1)] = 1            
        #print dp[0]
        for i in xrange(k - 1):
            for (y1, x1), v in dp[i].items():
                if y1 > n or x1 > m:
                    continue
                for x2 in xrange(x1, m + 1):
                    nxt = (y1, x2 + 1)
                    #print (y1, x1), nxt, (y1, x1, n - 1, x2), msum(y1, x1, n - 1, x2), v
                    if msum(y1, x1, n, x2):
                        dp[i + 1][nxt] += v
                        dp[i + 1][nxt] %= MOD

                for y2 in xrange(y1, n + 1):
                    nxt = (y2 + 1, x1)
                    #print (y1, x1), nxt, (y1, x1, y2, m - 1), msum(y1, x1, y2, m - 1), v
                    if msum(y1, x1, y2, m):
                        dp[i + 1][nxt] += v
                        dp[i + 1][nxt] %= MOD
            #print dp[i + 1]
        res = 0
        for (y, x), v in dp[k - 1].items():
            if y == n + 1:
                res += v
        return res % MOD
