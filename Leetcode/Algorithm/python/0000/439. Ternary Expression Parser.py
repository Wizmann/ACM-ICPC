class Solution(object):
    def parseTernary(self, expression):
        self.n = len(expression)
        self.expr = expression
        self.ptr = 0
        return self.eval()
        
    def eval(self):
        cur = self.expr[self.ptr]
        self.ptr += 1
        if self.ptr == self.n or self.expr[self.ptr] == ':':
            return cur
        else:
            flag = True if cur == 'T' else False
            self.ptr += 1
            a = self.eval()
            self.ptr += 1
            b = self.eval()
            return a if flag else b
