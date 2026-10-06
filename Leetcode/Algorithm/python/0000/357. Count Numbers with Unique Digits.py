def A(a, b):
    res = 1
    for i in xrange(a):
        res *= b - i
    return res

class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        if n == 0:
            return 1
        return A(n, 10) - A(n - 1, 9) + self.countNumbersWithUniqueDigits(n - 1)
        
#####

N = (1 << 10)

class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        dp = [[0 for i in xrange(N)] for j in xrange(2)]
        dp[0][0] = 1
        
        p = 0
        res = 0
        for i in xrange(n):
            q = p ^ 1
            dp[q] = [0 for i in xrange(N)]
            for j in xrange(N):
                for k in xrange(1, 10):
                    if j & (1 << k):
                        continue
                    u = j | (1 << k)
                    dp[q][u] += dp[p][j]
            res += sum(dp[q])
            for j in xrange(N):
                if j & 1:
                    continue
                dp[q][j | 1] += dp[p][j]
            p = q
        return res + 1
