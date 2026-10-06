INF = 10 ** 10
class Solution(object):
    def minDays(self, n):
        self.d = {}
        res = self.dfs(n, 0)
        return res
    
    def dfs(self, n, day):
        if n == 0:
            return 0
        if n in self.d:
            return self.d[n]
        if day > 65:
            return INF
        mini = INF
        if n % 2 == 0:
            mini = min(mini, self.dfs(n / 2, day + 1))
        if n % 3 == 0:
            mini = min(mini, self.dfs(n / 3, day + 1))
        mini = min(mini, self.dfs(n - 1, day + 1))
        if mini < INF:
            self.d[n] = mini + 1
        return mini + 1


assert Solution().minDays(1421) == 13
assert Solution().minDays(1069192976) == 33
assert Solution().minDays(10) == 4
assert Solution().minDays(6) == 3
assert Solution().minDays(1) == 1
assert Solution().minDays(10 ** 10) == 32
assert Solution().minDays(2 * (10 ** 9)) > 0

