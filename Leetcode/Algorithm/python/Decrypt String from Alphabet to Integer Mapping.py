class Solution(object):
    def freqAlphabets(self, s):
        res = ''
        s = list(s)
        while s:
            c = s.pop()
            print c
            if c == '#':
                a, b = s.pop(), s.pop()
                res += self.decrypt(b + a)
            else:
                res += self.decrypt(c)
        return res[::-1]
    
    def decrypt(self, c):
        c = int(c)
        return chr(ord('a') + c - 1)
