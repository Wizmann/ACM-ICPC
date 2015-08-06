import re

class Solution:
    # @param {string} input
    # @return {integer[]}
    def diffWaysToCompute(self, input):
        expr = filter(lambda x: x, re.split('([^\d])', input))
        return self.do_compute(expr)
        
    def do_compute(self, expr):
        if len(expr) == 1:
            return [int(expr[0])]
            
        res = []
        for i, item in enumerate(expr):
            if item.isdigit():
                continue
            a = expr[:i]
            b = expr[i + 1:]
            
            As = self.do_compute(a)
            Bs = self.do_compute(b)
            
            for A in As:
                for B in Bs:
                    res.append(
                        eval('%d%s%d' % (A, item, B))
                    )
        return res
