INF = 10 ** 10

class Solution(object):
    def minimumScore(self, s, t):
        n = len(s)
        m = len(t)
        dp1 = [0 for i in xrange(n + 1)]

        p, q = 0, 0
        while p < n and q < m:
            while p < n and s[p] != t[q]:
                p += 1
                dp1[p] = dp1[p - 1]
            if p < n:
                dp1[p + 1] = dp1[p] + 1
            p += 1
            q += 1
        
        ans = m - max(dp1)
        p, q = n - 1, m - 1
        pre = 0
        while p >= 0 and q >= 0:
            while p >= 0 and s[p] != t[q]:
                p -= 1
            if p >= 0:
                pre += 1
                ans = min(ans, max(0, m - pre - dp1[p]))
            p -= 1
            q -= 1
        return ans
