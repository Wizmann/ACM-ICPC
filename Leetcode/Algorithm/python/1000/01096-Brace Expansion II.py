import itertools

class Solution(object):
    def braceExpansionII(self, expression):
        expression = '{' + expression + '}'
        return sorted(set(self.solve(expression)))
    
    def solve(self, expr):
        n = len(expr)
        #print 'expr:', expr

        if '{' not in expr and '}' not in expr:
            return map(lambda c: c.strip(), expr.split(','))

        st = []
        subexprs = []
        depth = 0
        for i, c in enumerate(expr):
            if c == ',' and depth == 0:
                subexprs.append(''.join(st))
                st = []
            else:
                if c == '{':
                    depth += 1
                elif c == '}':
                    depth -= 1
                st.append(c)
        if subexprs and st:
            subexprs.append(''.join(st))

        if subexprs:
            res = []
            for subexpr in subexprs:
                res += self.solve(subexpr)
            return res

        newexpr = ''
        flag = False
        depth = 0
        for i, c in enumerate(expr):
            if c.isalpha() and depth == 0:
                newexpr += '{%s}' % c
                flag = True
            else:
                if c == '{':
                    depth += 1
                elif c == '}':
                    depth -= 1
                newexpr += c
        if flag:
            return self.solve(newexpr)

        #print 'expr:', expr
        
        tokens = []
        st = []
        subexprs = []
        for i, c in enumerate(expr):
            tokens.append(c)
            if c == '{':
                st.append(i)
            elif c == '}':
                st.pop()
                if not st:
                    subexpr = ''.join(tokens)
                    if subexpr[0] == '{' and subexpr[-1] == '}':
                        subexpr = subexpr[1: -1]
                    subexprs.append(self.solve(subexpr))
                    tokens = []

        #print subexprs
            
        res = []
        for item in sorted(itertools.product(*subexprs)):
            res.append(''.join(item))
        #print 'res:', res
        return sorted(set(res))

assert Solution().braceExpansionII("{{a{b,c}}d}") == ['abd', 'acd']
assert Solution().braceExpansionII("{{a,z},a{b,c},{ab,z}}") == ["a","ab","ac","z"]
assert Solution().braceExpansionII("{a,ab}c") == ["abc", "ac"]
assert Solution().braceExpansionII("{{a{b,c}}d}") == ['abd', 'acd']
assert Solution().braceExpansionII("{a{b,c}}") == ['ab', 'ac']
assert Solution().braceExpansionII("{a, b}{c, d}") == ['ac', 'ad', 'bc', 'bd']
assert Solution().braceExpansionII("{a}") == ["a"]
assert Solution().braceExpansionII("{a, b, c}") == ["a", "b", "c"]
assert Solution().braceExpansionII("{a{b,c}}{{d,e}f{g,h}}") == ["abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"]
