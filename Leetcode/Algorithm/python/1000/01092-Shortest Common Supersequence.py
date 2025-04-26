from collections import defaultdict

INF = 10 ** 10

class Solution(object):
    def shortestCommonSupersequence(self, str1, str2):
        n = len(str1)
        m = len(str2)
        
        d = defaultdict(list)
        
        dp = [ [0 for j in xrange(m + 1)] for i in xrange(n + 1)]
        
        for i in xrange(1, n + 1):
            for j in xrange(1, m + 1):
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])
                if str1[i - 1] == str2[j - 1]:
                    if dp[i - 1][j - 1] + 1 >= dp[i][j]:
                        dp[i][j] = dp[i - 1][j - 1] + 1
                        d[dp[i][j]].append((i, j))
        
        c = ''
        maxi = dp[n][m]
        y, x = INF, INF
        # print d
        for v in xrange(maxi, 0, -1):
            for i, j in d[v]:
                if i < y and j < x:
                    assert str1[i - 1] == str2[j - 1]
                    c += str1[i - 1]
                    y, x = i, j
                    break
            else:
                assert False
        c = c[::-1]
        assert len(c) == maxi
        # print c, maxi
        res = ''
        p, q, w = 0, 0, 0
        while p < n and q < m and w < len(c):
            cur = c[w]
            
            if str1[p] != cur:
                res += str1[p]
                p += 1
            if str2[q] != cur:
                res += str2[q]
                q += 1
            if str1[p] == str2[q] == cur:
                res += str1[p]
                p += 1
                q += 1
                w += 1
        assert w == len(c)
        res += str1[p:] + str2[q:]
        return res
            
            
            
                    
