class Solution(object):
    def stringHash(self, s, k):
        res = ''
        for i in xrange(len(s) / k):
            sub = s[i * k: (i + 1) * k]
            tot = 0
            for c in sub:
                tot += ord(c) - ord('a')
            tot %= 26
            res += chr(ord('a') + tot)
        return res
