INF = 10 ** 10

class Solution(object):
    def minDifficulty(self, jd, d):
        if len(jd) < d:
            return -1
        self.n = len(jd)
        self.jd = jd
        self.dp = {}
        return self.dfs(0, d)
    
    def dfs(self, pos, day):
        if day == 0:
            if pos != self.n:
                return INF
            return 0
        key = (pos, day)
        if key in self.dp:
            return self.dp[key]
        
        maxi = -1
        res = INF
        for i in xrange(pos, self.n):
            maxi = max(maxi, self.jd[i])
            res = min(res, self.dfs(i + 1, day - 1) + maxi)
        self.dp[key] = res
        return res
