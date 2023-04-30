class Solution(object):
    def smallestBeautifulString(self, s, k):
        self.k = k
        s = map(lambda c: ord(c) - ord('a'), s)
        n = len(s)
        s, p = self.add_one(s, n - 1)
        print len(s)
        z = n - 1
        while s:
            pos = self.check(s, p)
            if pos == -1:
                return ''.join(map(lambda x: chr(x + ord('a')), s))
            for i in xrange(pos + 1, z):
                s[i] = 0
            z = min(z, pos + 1)
            s, p = self.add_one(s, pos)
            # print s
        return ''
            
    def check(self, s, p):
        n = len(s)
        for i in xrange(p, n):
            if i - 1 >= 0 and s[i] == s[i - 1]:
                return i
            if i - 2 >= 0 and s[i] == s[i - 2]:
                return i
        return -1
        
    def add_one(self, s, pos):
        n = len(s)
        s[pos] += 1
        g = 0
        for i in xrange(pos, -1, -1):
            s[i] += g
            g = s[i] / self.k
            s[i] %= self.k
            if not g:
                return s, i
        if g:
            return [], -1
        assert False
        
