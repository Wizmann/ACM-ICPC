class Solution(object):
    def getKth(self, lo, hi, k):
        self.d = {}
        ns = []
        for i in xrange(lo, hi + 1):
            ns.append((self.dfs(i), i))
        ns.sort()
        return ns[k - 1][1]
    
    def dfs(self, n):
        if n == 1:
            return 0
        if n in self.d:
            return self.d[n]
        if n % 2 == 0:
            res = self.dfs(n / 2) + 1
        else:
            res = self.dfs(n * 3 + 1) + 1
        self.d[n] = res
        return res
