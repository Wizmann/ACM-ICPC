import re
class Evaluation:
    def evaluate(self, expr):
        expr = re.split(r"([\+\-\*])", str(expr))
        return self.do_evaluate(expr)
    
    def do_evaluate(self, expr):
        for op in "+-*":
            try:
                idx = (len(expr) - 1) - expr[::-1].index(op)
            except:
                idx = -1
        
            if idx != -1:
                a = self.do_evaluate(expr[:idx])
                b = self.do_evaluate(expr[idx + 1:])
                return {
                    "+": a + b,
                    "-": a - b,
                    "*": a * b
                }[op]
        return int(expr[0])
