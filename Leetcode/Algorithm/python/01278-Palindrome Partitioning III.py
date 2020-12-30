INF = 10 ** 10

class Solution(object):
    def palindromePartition(self, s, kk):
        n = len(s)
        dp1 = [ [INF for i in xrange(n)] for j in xrange(n) ]
        
        for i in xrange(n):
            dp1[i][i] = 0
            
        for i in xrange(1, n):
            for j in xrange(n):
                l = j
                r = j + i
                if l < 0 or r >= n:
                    continue
                res = 0
                if s[l] != s[r]:
                    res += 1
                if l != r - 1:
                    res += dp1[l + 1][r - 1]
                dp1[l][r] = res
        
        #print dp1
        dp2 = [ [INF for i in xrange(n)] for j in xrange(2) ]
        
        for i in xrange(n):
            dp2[0][i] = dp1[0][i]
            
        p = 0
        for i in xrange(1, kk):
            q = p ^ 1
            dp2[q] = [INF for i in xrange(n)]
            
            for j in xrange(n):
                for k in xrange(j + 1, n):
                    dp2[q][k] = min(dp2[q][k], dp2[p][j] + dp1[j + 1][k])
            #print dp2[q]
            p = q
        return dp2[p][n - 1]
            
        
