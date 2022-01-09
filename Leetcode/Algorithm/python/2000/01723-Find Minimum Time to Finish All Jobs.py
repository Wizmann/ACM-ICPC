INF = 10 ** 10

class Solution(object):
    def minimumTimeRequired(self, jobs, k):
        n = len(jobs)
        
        self.d = {}
        for i in xrange(1, 1 << n):
            tot = 0
            for j in xrange(n):
                if i & (1 << j):
                    tot += jobs[j]
            self.d[i] = tot
        
        self.dp = {}
        return self.dfs(0, k, (1 << n) - 1)
        
    def dfs(self, cur, k, rem):
        if cur == k:
            if rem == 0:
                return 0
            return INF
        dp_key = (cur, rem)
        if dp_key in self.dp:
            return self.dp[dp_key]
        res = INF

        sub = rem
        while sub:
            value = self.d[sub]
            if value <= res:
                res = min(res, max(value, self.dfs(cur + 1, k, rem ^ sub)))
            sub = (sub - 1) & rem

        self.dp[dp_key] = res
        return res
