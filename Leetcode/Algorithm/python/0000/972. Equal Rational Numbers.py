def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

class Solution(object):
    def isRationalEqual(self, S, T):
        v1 = self.getValue(S)
        v2 = self.getValue(T)
        print v1, v2
        return self.equals(v1, v2)
    
    def getValue(self, S):
        iv = 0
        if '.' in S:
            S = S.split('.')
            iv = int(S[0])
            S = S[1]
        else:
            iv = int(S)
            return (iv, 1)
        u = 0
        t = 1
        for c in S:
            if c != '(':
                t *= 10
                u = u * 10 + int(c)
            else:
                break
        v = self.add(iv, 1, u, t)
        if '(' in S:
            S = S[S.index('(') + 1 :S.index(')')]
            v = self.add(v[0], v[1], int(S), (10 ** len(S) - 1) * t)
        return v
    
    def add(self, a0, a1, b0, b1):
        v0 = a0 * b1 + a1 * b0
        v1 = a1 * b1
        if v0 == 0:
            return (0, 1)
        g = gcd(v0, v1)
        return v0 / g, v1 / g
    
    def equals(self, v1, v2):
        a0, a1 = v1
        b0, b1 = v2
        return a0 * b1 == a1 * b0
