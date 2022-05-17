class Solution(object):
    def divisorSubstrings(self, num, k):
        s = str(num)
        n = len(s)
        res = 0
        for i in xrange(n - k + 1):
            sub = int(''.join(s[i: i + k]))
            if sub and num % sub == 0:
                res += 1
        return res
