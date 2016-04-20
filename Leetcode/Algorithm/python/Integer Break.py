class Solution(object):
    def integerBreak(self, n):
        d = {
            1: 1,
            2: 1,
            3: 2,
        }
        if n in d:
            return d[n]
        a = n / 3
        b = n % 3
        if b == 0:
            return 3 ** a
        elif b == 1:
            return (3 ** (a - 1)) * 4
        else:
            return (3 ** a) * 2
