import re

class Solution(object):
    def basicCalculatorIV(self, expression, evalvars, evalints):
        self.d = dict(zip(evalvars, evalints))

        tokens = []
        for item in re.split(r'([^[^\-a-zA-Z\d])', expression):
            if not item.strip():
                continue

            if item in self.d:
                token = self.d[item]
            else:
                token = item

            if self.is_int(token):
                tokens.append({ 1: int(token) })
            elif token.isalpha():
                tokens.append({ (token, ): 1 })
            else:
                tokens.append(token)
        res = []
        for (key, value) in sorted(self.eval(tokens).items(), key=lambda (k, v): self.degree(k)):
            if not value:
                continue
                
            if key == 1:
                res.append(str(value))
            else:
                s = '%d*' % value + '*'.join(key)
                res.append(s)
        return res

    def degree(self, key):
        if key == 1:
            return (0, '')
        return -len(key), key

    def is_int(self, token):
        try:
            u = int(token)
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
                else:
                    assert False

            res = tokens.pop(0)
            while tokens:
                op = tokens.pop(0)
                cur = tokens.pop(0)

                if op == '-':
                    for key in cur.keys():
                        cur[key] = -1 * cur[key]
                res = self.add(res, cur)
            return res

    def add(self, a, b):
        res = {}
        for key in set(a.keys() + b.keys()):
            v1 = a.get(key, 0)
            v2 = b.get(key, 0)
            res[key] = v1 + v2
            if not res[key]:
                del res[key]
        return res

    def mult(self, a, b):
        res = {}
        for k1 in a.keys():
            for k2 in b.keys():
                if k1 == 1:
                    key = k2
                elif k2 == 1:
                    key = k1
                else:
                    key = tuple(sorted(k1 + k2))
                v1 = a.get(k1, 0)
                v2 = b.get(k2, 0)

                res[key] = res.get(key, 0) + v1 * v2
                if not res[key]:
                    del res[key]
        return res
