MOD = (10 ** 9) + 7

class Solution(object):
    def numberOfUniqueGoodSubsequences(self, binary):
        a, b = 0, 0
        n = len(binary)
        flag = False
        for i in xrange(n - 1, -1, -1):
            if binary[i] == '0':
                a, b = a + b + 1, b
                a %= MOD
                flag = True
            else:
                a, b = a, a + b + 1
                b %= MOD
        return (b + flag) % MOD
