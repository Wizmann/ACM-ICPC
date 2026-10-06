class Solution(object):
    def clumsy(self, N):
        expr = ''
        ops = '*/+-'
        for i, num in enumerate(range(1, N + 1)[::-1]):
            op = ops[i % 4]
            expr += ' %d %s' % (num, op)
        expr = expr[:-1]
        return eval(expr)
