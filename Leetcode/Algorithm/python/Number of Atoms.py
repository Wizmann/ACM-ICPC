from collections import defaultdict

class Parser(object):
    def __init__(self, s):
        self.s = s
        self.ptr = 0
        
    def parse(self):
        formula = []
        while self.ptr < len(self.s):
            # print self.s[self.ptr], self.ptr
            cur = ''
            num = 0
            if self.s[self.ptr] == '(':
                self.ptr += 1
                cur = self.parse()
                self.ptr += 1
            elif self.s[self.ptr] == ')':
                break
            else:
                while self.ptr < len(self.s) and self.s[self.ptr].isalpha():
                    if cur and self.s[self.ptr].isupper():
                        break
                    cur += self.s[self.ptr]
                    self.ptr += 1
                    
            while self.ptr < len(self.s) and self.s[self.ptr].isdigit():
                num = num * 10 + int(self.s[self.ptr])
                self.ptr += 1
                
            formula.append((cur, max(1, num)))
        return formula


class Solution(object):
    def countOfAtoms(self, formula):
        f = Parser(formula).parse()
        return ''.join(
            map(lambda (k, v): "%s%s" % (k, '' if v == 1 else str(v)),
                sorted(self.count(f).items(), key=lambda (k, v): k)
            ))
        
    def count(self, formula):
        d = defaultdict(int)
        for (key, value) in formula:
            if isinstance(key, unicode):
                d[key] += value
            else:
                dd = self.count(key)
                for (kk, vv) in dd.items():
                    d[kk] += vv * value
        return d
