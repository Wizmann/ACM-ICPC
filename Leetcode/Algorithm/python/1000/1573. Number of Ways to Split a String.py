MOD = (10 ** 9) + 7

class Solution(object):
    def numWays(self, s):
        ones = []
        for i, c in enumerate(s):
            if c == '1':
                ones.append(i)
        m = len(ones)
        n = len(s)
        if m == 0:
            return (n - 1) * (n - 2) / 2 % MOD
        if m % 3 != 0:
            return 0
        l1, r1 = ones[m / 3 - 1], ones[m / 3]
        l2, r2 = ones[m / 3 * 2 - 1], ones[m / 3 * 2]
        return (r1 - l1) * (r2 - l2) % MOD
        
