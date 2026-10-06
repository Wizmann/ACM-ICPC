class Solution:
    def addBinary(self, a, b):
        a = map(int, a)[::-1]
        b = map(int, b)[::-1]
        c = []
        g = 0
        for (u, v) in itertools.izip_longest(a, b, fillvalue=0):
            s = u + v + g
            c.append(s & 1)
            g = s / 2
        if g:
            c.append(g)
        return ''.join(map(str, c)[::-1])
