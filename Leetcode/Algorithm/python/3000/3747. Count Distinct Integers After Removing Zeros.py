class Solution(object):
    def countDistinct(self, n):
        """
        :type n: int
        :rtype: int
        """
        ns = map(int, str(n))
        m = len(ns)
        self.dp = {}
        return self.solve(0, m, ns, pre=True, lt=False) - 1

    def solve(self, cur, n, ns, pre, lt):
        key = cur
        if cur == n:
            return 1
        if not pre and lt and key in self.dp:
            return self.dp[key]
        res = 0
        for i in xrange(10):
            if not pre and i == 0:
                continue
            if lt:
                res += self.solve(cur + 1, n, ns, pre and i == 0, True)
            elif i <= ns[cur]:
                res += self.solve(cur + 1, n, ns, pre and i == 0, i < ns[cur])
        if not pre and lt:
            self.dp[key] = res
        return res


