MOD = (10 ** 9) + 7

class Solution(object):
    def distinctSubseqII(self, S):
        n = len(S)
        dp = {}
        
        res = 1
        for c in S:
            pre = res
            if c not in dp:
                res *= 2
            else:
                res = res * 2 - dp[c]
            dp[c] = pre
            res = (res % MOD + MOD) % MOD
        return res % MOD - 1
