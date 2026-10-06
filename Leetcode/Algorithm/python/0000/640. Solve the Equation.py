import re
class Solution(object):
    def solveEquation(self, equation):
        assert self.parse("2x+1")  == [2, 1]
        assert self.parse("-2x-2") == [-2, -2]
        
        l, r = equation.split('=')
        assert l and r
        
        l = self.parse(l)
        r = self.parse(r)
       
        l[0] -= r[0]
        l[1] -= r[1]
        
        if l[0] == l[1] == 0:
            return 'Infinite solutions'
        elif not l[0] and l[1]:
            return 'No solution'
        else:
            a, b = l
            return 'x=%d' % (-b / a)
        
    def parse(self, s):
        if not s.startswith('-'):
            s = '+' + s
        tokens = filter(
                lambda token: token, 
                re.split("([+-]\d*x?)", s))

        x, one = 0, 0
        
        for token in tokens:
            if token.endswith('x'):
                if token == '+x':
                    num = 1
                elif token == '-x':
                    num = -1
                else:
                    num = int(token[:-1])
                x += num
            else:
                num = int(token)
                one += num
        return [x, one]

S = Solution()
assert S.solveEquation("x+5-3+x=6+x-2") == 'x=2'
assert S.solveEquation("x=x") == "Infinite solutions"
assert S.solveEquation("2x=x") == "x=0"
assert S.solveEquation("2x+3x-6x=x+2") == 'x=-1'
assert S.solveEquation("x=x+2") == "No solution"
