from collections import defaultdict

MOD = (10 ** 9) + 7
HATS = 40

class Solution(object):
    def numberWays(self, hats):
        n = len(hats)
        dp = defaultdict(int)
        dp[0] = 1
        for i in xrange(HATS):
            nxt = defaultdict(int)
            for j in xrange(1 << n):
                nxt[j] += dp[j]
                nxt[j] %= MOD
                for k in xrange(n):
                    if (1 << k) & j:
                        continue
                    if (i + 1) not in hats[k]:
                        continue
                    nxt[j | (1 << k)] += dp[j]
                    nxt[j | (1 << k)] %= MOD
            dp = nxt
        return dp[(1 << n) - 1] % MOD

assert Solution().numberWays([[3,4],[4,5],[5]]) == 1
assert Solution().numberWays([[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]) == 24
assert Solution().numberWays([[1,2,3],[2,3,5,6],[1,3,7,9],[1,8,9],[2,5,7]]) == 111
assert Solution().numberWays([[1,4,5,8,9,11,12,13,14,15,16,17,19,20,22,24,27,28,30],[4,5,6,8,14,21,22,29],[1,2,3,5,7,11,12,13,15,16,17,18,19,20,21,23,25,26,28,30],[8,13,30],[5,10,17,19,20,25],[1,2,8,13,14,18,19,20,21,22,24,30],[4,5,7,8,11,12,15,16,18,19,23,28]]) == 3652998
assert Solution().numberWays([[1,2,4,6,7,8,9,11,12,13,14,15,16,18,19,20,23,24,25],[2,5,16],[1,4,5,6,7,8,9,12,15,16,17,19,21,22,24,25],[1,3,6,8,11,12,13,16,17,19,20,22,24,25],[11,12,14,16,18,24],[2,3,4,5,7,8,13,14,15,17,18,21,24],[1,2,6,7,10,11,13,14,16,18,19,21,23],[1,3,6,7,8,9,10,11,12,14,15,16,18,20,21,22,23,24,25],[2,3,4,6,7,10,12,14,15,16,17,21,22,23,24,25]]) == 778256459


