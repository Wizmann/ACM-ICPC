class Solution(object):
    def shiftingLetters(self, s, shifts):
        n = len(s)
        mv = [0 for i in xrange(n + 1)]
        for (a, b, c) in shifts:
            if c == 0:
                c = -1
            mv[a] += c
            mv[b + 1] -= c
        
        cur = 0
        res = ''
        for i in xrange(n):
            cur += mv[i]
            res += chr(((ord(s[i]) - ord('a') + cur) % 26 + 26) % 26 + ord('a'))
        return res
