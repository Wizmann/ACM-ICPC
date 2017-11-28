def isdigit(expr):
    try:
        _ = int(expr)
        return True
    except:
        return False

class Parser(object):
    def __init__(self, expr):
        self.ptr = 0
        self.expr = expr
        
    def parse(self):
        exprs = []
        while self.ptr < len(self.expr):
            if self.expr[self.ptr] == ' ':
                self.ptr += 1
            elif self.expr[self.ptr] == '(':
                self.ptr += 1
                exprs.append(self.parse())
            elif self.expr[self.ptr] == ')':
                self.ptr += 1
                break
            else:
                token = ''
                while self.ptr < len(self.expr) and self.expr[self.ptr] not in '() ':
                    token += self.expr[self.ptr]
                    self.ptr += 1
                if isdigit(token):
                    exprs.append(int(token))
                else:
                    exprs.append(token)
        return exprs
        
assert Parser('(add 1 2)').parse() == [['add', 1, 2]]
assert Parser('(mult 3 (add 2 3))').parse() == [['mult', 3, ['add', 2, 3]]]
assert Parser('(let a1 3 b2 (add a1 1) b2)').parse() == [['let', 'a1', 3, 'b2', ['add', 'a1', 1], 'b2']]

class Solution(object):
    def evaluate(self, expression):
        expression = expression.encode('ascii','ignore')
        self.scope = []
        expr = Parser(expression).parse()
        return self.do_evaluate(expr)
        
    def do_evaluate(self, expr):
        if isinstance(expr, int):
            return expr
        elif isinstance(expr, str):
            return self.get_var(expr)
                
        cmd = expr[0]
        
        if cmd in ['add', 'mult']:
            assert len(expr) == 3
            a = self.do_evaluate(expr[1])
            b = self.do_evaluate(expr[2])
            if cmd == 'add':
                return a + b
            else:
                return a * b
        else:
            n = len(expr)
            self.scope.append({})
            for i in xrange(1, n - 1, 2):
                a, b = expr[i], expr[i + 1]
                assert isinstance(a, str)
                self.scope[-1][a] = self.do_evaluate(b)
            res = self.do_evaluate(expr[-1])
            self.scope.pop()
            return res
    
    def get_var(self, var):
        print self.scope, var
        for d in self.scope[::-1]:
            if var in d:
                return d[var]
        return None

assert Solution().evaluate('(let x (add 12 -7) (mult x x))') == 25
assert Solution().evaluate('(add 1 2)') == 3
assert Solution().evaluate('(mult 3 (add 2 3))') == 15
assert Solution().evaluate('(let x 2 (mult x 5))') == 10
assert Solution().evaluate('(let x 3 x 2 x)') == 2
assert Solution().evaluate('(let x 1 y 2 x (add x y) (add x y))') == 5
assert Solution().evaluate('(let a1 3 b2 (add a1 1) b2)') == 4
assert Solution().evaluate('(let x 2 (add (let x 3 (let x 4 x)) x))') == 6
