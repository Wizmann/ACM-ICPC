def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def lcm(a, b):
    return a * b / gcd(a, b)

class Solution(object):
    def findLexSmallestString(self, s, a, b):
        n = len(s)
        rr = lcm(n, b)
        mini = '~'
        for i in xrange(rr):
            mini = min(mini, self.solve(s[:], a, b % 2 != 0))
            s = s[b:] + s[:b]
        return mini
            
    def solve(self, s, a, flag):
        n = len(s)
        sa = s[::2]
        sb = s[1::2]
        
        sb = self.get_mini(sb, a)
        if flag:
            sa = self.get_mini(sa, a)
        res = ['x' for i in xrange(n)]
        for i in xrange(n):
            if i % 2 == 0:
                res[i] = sa[i / 2]
            else:
                res[i] = sb[i / 2]
        # print s, sa, sb
        return ''.join(res)
    
    def get_mini(self, s, delta):
        s = map(int, s)
        mini = '~'
        for i in xrange(10):
            m = len(s)
            for j in xrange(m):
                s[j] = (s[j] + delta) % 10
            mini = min(mini, ''.join(map(str, s)))
        return mini
            
