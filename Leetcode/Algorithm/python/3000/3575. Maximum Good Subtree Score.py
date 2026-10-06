from collections import defaultdict

MOD = int(1e9 + 7)
INF = 10 ** 10

def fill(nxt):
    bits = 0
    while nxt:
        if bits & (1 << (nxt % 10)):
            return -1
        bits |= 1 << (nxt % 10)
        nxt /= 10
    return bits

class Solution(object):
    def goodSubtreeSum(self, vals, par):
        """
        :type vals: List[int]
        :type par: List[int]
        :rtype: int
        """
        self.g = defaultdict(list)
        for i, p in enumerate(par):
            if p == -1:
                continue
            self.g[p].append(i)
        self.n = len(vals)
        self.vals = vals
        res = 0
        for i in xrange(self.n):
            self.dp = defaultdict(int)
            self.dfs(i)
            score = max(self.dp.values() + [0])
            # print i, score
            res = (res + score) % MOD
        return res

    def dfs(self, cur):
        score = self.vals[cur]
        bits = fill(self.vals[cur])        
        mask = ((1 << 10) - 1) ^ bits
        i = mask
        # print i
        while i and bits != -1:
            assert (i & bits) == 0
            if self.dp[i]:
                # print cur, i, self.dp[i], score
                nxt = i | bits
                self.dp[nxt] = max(self.dp[nxt], self.dp[i] + score)
            i = (i - 1) & mask
        if bits != -1:
            self.dp[bits] = max(self.dp[bits], score)
        for nxt in self.g[cur]:
            self.dfs(nxt)
