INF = 10 ** 10

class Solution(object):
    def minCost(self, n, cuts):
        cuts = sorted(cuts + [0, n])
        m = len(cuts)
        self.sticks = []
        for i in xrange(m - 1):
            self.sticks.append(cuts[i + 1] - cuts[i])
        self.d = {}
        res = self.dfs(0, len(self.sticks) - 1)
        return res

    def get_length(self, l, r):
        if l <= r:
            return sum(self.sticks[l: r + 1])
        else:
            return -INF

    def dfs(self, l, r):
        if l >= r:
            return 0
        key = (l, r)
        if key in self.d:
            return self.d[key]
        cur = self.get_length(l, r)
        if r - l == 1:
            return cur
        mini = INF
        for i in xrange(l, r):
            mini = min(mini, cur + self.dfs(l, i) + self.dfs(i + 1, r))
        self.d[key] = mini
        return mini

assert Solution().minCost(5, [1, 4]) == 9
assert Solution().minCost(30, [18,15,13,7,5,26,25,29]) == 92
assert Solution().minCost(3, [1]) == 3
assert Solution().minCost(7, [1, 5, 4, 3]) == 16
assert Solution().minCost(9, [5,6,1,4,2]) == 22

