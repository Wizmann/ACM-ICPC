import re

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)
    
def lcm(a, b):
    return a * b / gcd(a, b)

class Solution(object):
    def fractionAddition(self, expr):
        assert self.calc((0, 1), '+', "1/2") == (1, 2)
        assert self.calc((1, 1), '+', "1/2") == (3, 2)
        assert self.calc((1, 1), '-', "1/2") == (1, 2)
        assert self.calc((1, 2), '-', "1/1") == (-1, 2)
        
        if not expr:
            return '0/1'
        
        if expr[0] in '+-':
            expr = '0/1' + expr
        
        tokens = re.split('([+-])', expr)
        ans = (0, 1)
        
        ans = self.calc(ans, '+', tokens[0])
        
        for i in xrange(1, len(tokens), 2):
            ans = self.calc(ans, tokens[i], tokens[i + 1])
        
        return '%d/%d' % ans
        
    def calc(self, a, op, b):
        b = map(int, b.split('/'))
        
        l = lcm(a[1], b[1])
        a = (a[0] * l / a[1], l)
        b = (b[0] * l / b[1], l)
        
        if op == '+':
            c = (a[0] + b[0], l)
        else:
            c = (a[0] - b[0], l)
            
        g = gcd(c[0], c[1])
        return (c[0] / g, c[1] / g)
        

assert Solution().fractionAddition("-1/2+1/2") == "0/1"
assert Solution().fractionAddition("-1/2+1/2+1/3") == "1/3"
assert Solution().fractionAddition("1/3-1/2") == "-1/6"
assert Solution().fractionAddition("5/3+1/3") == "2/1"
