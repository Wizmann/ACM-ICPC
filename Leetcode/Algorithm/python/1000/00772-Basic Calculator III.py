import re

class Solution(object):
    def calculate(self, expression):
        tokens = []
        for token in re.split(r'([\+\-\*\/\(\)])', expression):
            token = token.strip()
            if not token:
                continue
            if self.is_int(token):
                token = int(token)
            tokens.append(token)
        print tokens
        return self.eval(tokens)

    def is_int(self, u):
        try:
            u = int(u)
            return True
        except:
            return False

    def eval(self, expr):
        if '(' in expr:
            o = expr[:]
            tokens = []
            while expr:
                cur = expr.pop(0)
                if cur == '(':
                    idx = 1
                    sub = []
                    while idx:
                        token = expr.pop(0)
                        if token == '(':
                            idx += 1
                        elif token == ')':
                            idx -= 1

                        if idx != 0:
                            sub.append(token)
                    cur = self.eval(sub)
                tokens.append(cur)
            return self.eval(tokens)
        else:
            tokens = [expr.pop(0)]
            while expr:
                op = expr.pop(0)
                if op in '+-':
                    tokens.append(op)
                    tokens.append(expr.pop(0))
                elif op == '*':
                    tokens.append(self.mult(tokens.pop(), expr.pop(0)))
                elif op == '/':
                    tokens.append(self.div(tokens.pop(), expr.pop(0)))
                else:
                    assert False

            res = tokens.pop(0)
            while tokens:
                op = tokens.pop(0)
                cur = tokens.pop(0)

                if op == '-':
                    cur = -cur
                res = self.add(res, cur)
            return res

    def add(self, a, b):
        return a + b

    def mult(self, a, b):
        return a * b
    
    def div(self, a, b):
        return a / b
