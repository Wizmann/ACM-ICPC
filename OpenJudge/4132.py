import re

def is_any_of(l, chars):
    for i, c in enumerate(l):
        if c in chars:
            return i
    return -1

class Solution(object):
    def calc(self, s):
        s = re.split('([^\d.])', s)
        s = filter(lambda x: x.strip(), s)
        return self.do_calc(s)

    def do_calc(self, s):
        idx = is_any_of(s, '(')
        
        if idx == -1:
            return self.do_calc2(s)
        else:
            p = idx
            c = 0
            while p < len(s):
                if s[p] == '(':
                    c += 1
                elif s[p] == ')':
                    c -= 1
                if c == 0:
                    s = s[:idx] + [str(self.do_calc(s[idx + 1: p]))] + s[p + 1:]
                    return self.do_calc(s)
                p += 1

    def do_calc2(self, s):
        idx = is_any_of(s, '+-')
        if idx == -1:
            res = float(s[0])
            for i in xrange(1, len(s), 2):
                sym = s[i]
                oph = s[i + 1]
                res = self.myeval(res, sym, oph)
            return res
        else:
            loph = self.do_calc2(s[:idx])
            roph = self.do_calc2(s[idx + 1:])
            return self.myeval(loph, s[idx], roph)

    def myeval(self, a, op, b):
        a = float(a)
        b = float(b)
        return {
            '+': lambda x, y: x + y,
            '-': lambda x, y: x - y,
            '*': lambda x, y: x * y,
            '/': lambda x, y: x / y,
        }[op](a, b)

S = Solution()

assert S.calc('1 + 2') == 3.00
assert S.calc('1 + 2 * 3') == 7.00
assert S.calc('1 - 2') == -1.00
assert S.calc('3.4') == 3.40
assert S.calc('7+8.3') == 15.30
assert abs(S.calc('3+4.5*(7+2)*(3)*((3+4)*(2+3.5)/(4+5))-34*(7-(2+3))') - 454.75) < 1e-3

print '%.2f' % S.calc(raw_input())
