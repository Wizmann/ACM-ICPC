MOD = (10 ** 9) + 7

class Solution(object):
    def countVowelPermutation(self, n):
        rules = [
            [1],
            [0, 2],
            [0, 1, 3, 4],
            [2, 4],
            [0],
        ]
        
        dp = [1, 1, 1, 1, 1]
        for i in xrange(n - 1):
            nxt = [0, 0, 0, 0, 0]
            for j in xrange(5):
                for k in rules[j]:
                    nxt[k] = (nxt[k] + dp[j]) % MOD
            dp = nxt[:]
        return sum(dp) % MOD
