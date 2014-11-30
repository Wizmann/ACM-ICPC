class Solution:
    # @param tokens, a list of string
    # @return an integer
    ops = {
        '+': lambda x, y: x + y,
        '-': lambda x, y: x - y,
        '*': lambda x, y: x * y,
        '/': lambda x, y: int(1. * x / y), 
    }
    def evalRPN(self, tokens):
        st = []
        for token in tokens:
            if token not in self.ops:
                st.append(token)
                continue
            a = st.pop()
            b = st.pop()
            c = self.calc(b, token, a)
            st.append(c)
        return int(st[0])
    
    def calc(self, a, op, b):
        return self.ops[op](int(a), int(b))
        
