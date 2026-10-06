import re

class Solution(object):
    def calculate(self, s):
        s = re.split("([^\d])", s)
        s = filter(lambda x: x.strip(), s)
        return self.do_calc(0, int(s[0]), s[1:])
    
    def do_calc(self, res, pre, s):
        for i in xrange(0, len(s), 2):
            op, num = s[i], s[i + 1]
            if op in ['*', '/']:
                pre = self.myeval(pre, op, num)
            else:
                res = res + pre
                pre = self.myeval(0, op, num)
        return res + pre
        
    def myeval(self, a, op, b):
        a = int(a)
        b = int(b)
        def cdiv(x, y):
            sig = 1 if x * y > 0 else -1
            return sig * (abs(x) / abs(y))
        return {
            '+': lambda x, y: x + y,
            '-': lambda x, y: x - y,
            '*': lambda x, y: x * y,
            '/': lambda x, y: cdiv(x, y)
        }[op](a, b)

