MOD = (10 ** 9) + 7
class Solution(object):
    def numSub(self, s):
        res = 0
        for sub in s.split('0'):
            if not sub:
                continue
            m = len(sub)
            res += ((m + 1) * m / 2) % MOD
            res %= MOD
        return res
            
