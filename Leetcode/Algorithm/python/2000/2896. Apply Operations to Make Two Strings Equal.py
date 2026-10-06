INF = 10 ** 10

class Solution(object):
    def minOperations(self, s1, s2, x):
        s1 = map(int, s1)
        s2 = map(int, s2)
        n = len(s1)
        ns = []
        for i in xrange(n):
            if s1[i] ^ s2[i] == 1:
                ns.append(i)
        # print ns
        self.x = x
        self.dp = {}
        res = self.dfs(0, ns, 0, False)
        if res >= INF:
            return -1
        return res

    def dfs(self, cur, ns, rem, flag):
        if cur == len(ns):
            if rem == 0 and flag == False:
                return 0
            return INF
        key = (cur, rem, flag)
        if key in self.dp:
            return self.dp[key]
        mini = INF
        if flag:
            assert cur > 0
            diff = min(self.x, ns[cur] - ns[cur - 1])
            mini = min(mini, self.dfs(cur + 1, ns, rem, False) + diff)
        else:
            if rem:
                mini = min(mini, self.dfs(cur + 1, ns, rem - 1, False) + self.x)
            mini = min(mini, self.dfs(cur + 1, ns, rem, True))
            mini = min(mini, self.dfs(cur + 1, ns, rem + 1, False))
        self.dp[key] = mini
        # print key, mini
        return mini

assert Solution().minOperations("10110", "00011", 4) == -1
assert Solution().minOperations('1100011000', '0101001010', 2) == 4
