class Solution:
    # @param {string} s
    # @return {integer}
    def calculate(self, s):
        op_s = []
        num_s = []
        
        s = re.split("([+-/*#()])", s.strip())
        s += ["#"]
        
        s = filter(lambda x: x, 
            map(lambda y: y.strip(), s))
        for c in s:
            if c.isdigit():
                num_s.append(int(c))
            elif not op_s:
                op_s.append(c)
            else:
                u = self.score(op_s[-1])
                v = self.score(c)
                if v > u:
                    op_s.append(c)
                else:
                    while op_s and self.score(op_s[-1]) >= v:
                        if op_s[-1] == '(' and c == ')':
                            op_s.pop()
                            break
                        elif op_s[-1] == '(':
                            break
                        
                        b = num_s.pop()
                        a = num_s.pop()
                        num_s.append(
                            self.do_eval(a, op_s.pop(), b)
                        )
                    
                    if c != ')':
                        op_s.append(c)
        return num_s[0]
                
    def score(self, op):
        if op in ['#', ')']:
            return -1
        if op in ['+', '-']:
            return 9
        if op in ['/', '*']:
            return 99
        if op in ['(']:
            return 999
    def do_eval(self, a, op, b):
        return {
            '+': a + b,
            '-': a - b,
            '*': a * b,
            '/': a / b if b != 0 else 0xdeadbeef,
        }[op]