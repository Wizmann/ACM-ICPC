from collections import defaultdict

MOD = 10 ** 9 + 7

class Solution(object):
    def numWays(self, words, target):
        n = len(words[0])
        m = len(target)
        
        dp = [ [0 for i in xrange(m + 1)] for j in xrange(2) ]
        dp[0][0] = 1
        
        d = [defaultdict(int) for i in xrange(n + 1)]
        
        for word in words:
            for i in xrange(1, n + 1):
                d[i][word[i - 1]] += 1
        
        p = 0
        for i in xrange(1, n + 1):
            q = p ^ 1
            dp[q] = dp[p][:]
            
            for (c, count) in d[i].items():
                for j in xrange(1, m + 1):
                    if c == target[j - 1]:
                        dp[q][j] = (dp[q][j] + dp[p][j - 1] * count) % MOD
            p = q
        return dp[p][m]
