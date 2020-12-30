class Solution(object):
    def parseBoolExpr(self, expression):
        return self.solve(expression)
    
    def solve(self, expr):
        if expr[0] == '(' and expr[-1] == ')':
            expr = expr[1: -1]
            
        if expr == 't':
            return True
        if expr == 'f':
            return False
        
        expr = list(expr)
        depth = 0
        for i, c in enumerate(expr):
            if c == '(':
                depth += 1
            if c == ')':
                depth -= 1
            if c == ',' and depth == 0:
                expr[i] = '$'
                
        expr = ''.join(expr)
        if '$' in expr:
            expr = expr.split('$')
            return map(self.solve, expr)
        
        if expr[0] == '!':
            return not self.solve(expr[1:])
        
        if expr[0] == '&':
            res = self.solve(expr[1:])
            if not isinstance(res, list):
                res = [res]
            return reduce(lambda x, y: x and y, res, True)
        
        if expr[0] == '|':
            res = self.solve(expr[1:])
            if not isinstance(res, list):
                res = [res]
            return reduce(lambda x, y: x or y, res, False)
