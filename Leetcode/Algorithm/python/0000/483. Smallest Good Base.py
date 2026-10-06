class Solution(object):
    def smallestGoodBase(self, n):
        n = int(n)
        i = 1
        ans = n
        while (1 << (i - 1)) <= n:
            ans = min(ans, self.solve(n, i))
            i += 1
        return str(ans)
    
    def solve(self, n, k):
        l, r = 1, n
        while l <= r:
            m = (l + r) >> 1
            t = self.calc(k, m)
            if t >= n:
                r = m - 1
            else:
                l = m + 1
        t = self.calc(k, l)
        if t != n:
            return n
        else:
            return l
        
    def calc(self, n, k):
        t = 0
        cur = 1
        for i in xrange(n):
            t += cur
            cur *= k
        return t

S = Solution()
for i in xrange(2, 10):
    for j in xrange(1, 10):
        assert S.calc(j, i) == int('1' * j, i)
