def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def lcm(a, b):
    return a * b / gcd(a, b)

class Solution(object):
    def mirrorReflection(self, p, q):
        if q == 0:
            return 0
        u = lcm(p, q) / q
        v = lcm(p, q) / p
        
        v %= 2
        u %= 2
        
        return {
            (0, 0): 'x',
            (0, 1): 0,
            (1, 0): 2,
            (1, 1): 1
        }[(v, u)]
