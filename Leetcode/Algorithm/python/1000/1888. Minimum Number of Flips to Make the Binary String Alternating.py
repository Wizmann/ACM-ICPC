INF = 10 ** 10

class Solution(object):
    def minFlips(self, s):
        n = len(s)
        s = map(int, s)
        res = INF
        if n % 2 == 0:
            cnt0, cnt1 = 0, 0
            for i in xrange(n):
                if s[i] != i % 2:
                    cnt0 += 1
                else:
                    cnt1 += 1
            return min(cnt0, cnt1)
        else:
            return min(self.solve(s), self.solve(map(lambda x: x ^ 1, s)))
        
    def solve(self, s):
        n = len(s)
        assert n % 2 == 1
        dp0 = [0 for i in xrange(n)]
        dp1 = [0 for i in xrange(n)]
        
        for i in xrange(n):
            dp0[i] = 0 if i - 1 < 0 else i - dp0[i - 1]
            if s[i] != 0:
                dp0[i] += 1
        for i in xrange(n - 1, -1, -1):
            dp1[i] = 0 if i + 1 == n else (n - i - 1) - dp1[i + 1]
            if s[i] != 0:
                dp1[i] += 1
        res = dp0[-1]
        # print dp0
        # print dp1
        for i in xrange(n):
            if i + 1 < n:
                res = min(res, dp0[i] + dp1[i + 1])
        return res
                    
