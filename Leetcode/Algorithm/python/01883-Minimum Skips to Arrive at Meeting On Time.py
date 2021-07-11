INF = 10 ** 10

class Solution(object):
    def minSkips(self, dist, speed, hoursBefore):
        n = len(dist)

        dp = [ [INF for i in xrange(n + 1)] for j in xrange(n + 1) ]
        suf = [0 for i in xrange(n + 1)]

        for i in xrange(n - 1, -1, -1):
            if i == n - 1:
                suf[i] = dist[i]
            else:
                suf[i] += suf[i + 1]
                suf[i] += (dist[i] + speed - 1) / speed * speed
        
        mini = INF
        for j in xrange(n):
            for i in xrange(n):
                if i > mini:
                    break

                pre1 = 0 if j - 1 < 0 else dp[i][j - 1]
                if pre1 < INF:
                    dp[i][j] = min(dp[i][j], (pre1 + speed - 1) / speed * speed + dist[j])
                    dp[i + 1][j] = min(dp[i + 1][j], pre1 + dist[j])

                if 1.0 * ((dp[i][j] + speed - 1) / speed * speed + suf[j + 1]) / speed <= hoursBefore:
                    mini = min(mini, i)

    
        return -1 if mini == INF else mini


# print Solution().minSkips([1, 3, 2], 4, 2)
