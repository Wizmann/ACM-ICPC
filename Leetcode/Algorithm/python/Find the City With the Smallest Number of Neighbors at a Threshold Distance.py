INF = 10 ** 10

class Solution(object):
    def findTheCity(self, n, edges, distanceThreshold):
        dp = [ [INF for i in xrange(n)] for j in xrange(n) ]
        
        for i in xrange(n):
            dp[i][i] = 0
        
        for (a, b, c) in edges:
            if c > distanceThreshold:
                continue
            dp[a][b] = min(dp[a][b], c)
            dp[b][a] = min(dp[b][a], c)
            
        for pivot in xrange(n):
            for i in xrange(n):
                for j in xrange(n):
                    dp[i][j] = min(dp[i][j], dp[i][pivot] + dp[pivot][j])
        
        mini = INF
        for i in xrange(n):
            cnt = 0
            for j in xrange(n):
                if i == j:
                    continue
                if dp[i][j] <= distanceThreshold:
                    cnt += 1
            if cnt <= mini:
                res = i
                mini = cnt
        return res
            
        
        
