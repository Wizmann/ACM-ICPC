import re

class Solution(object):
    def maximumGain(self, s, x, y):
        subs = filter(lambda x: x, re.split(r'[^ab]', s))
        flag = False
        if y > x:
            x, y = y, x
            flag = True
        res = 0
        for sub in subs:
            if flag:
                sub = ''.join(
                    map(lambda x: {'b': 'a', 'a': 'b'}[x], sub))
            res += self.solve(sub, x, y)
            
        return res
    
    def solve(self, s, x, y):
        assert x >= y
        st = []
        print s
        res = 0
        for c in s:
            if c == 'a':
                st.append('a')
            else:
                if st and st[-1] == 'a':
                    res += x
                    st.pop()
                else:
                    st.append('b')

        st2 = []
        for c in st:
            if c == 'b':
                st2.append('b')
            else:
                if st2 and st2[-1] == 'b':
                    res += y
                    st2.pop()
                else:
                    st2.append('a')
        return res
        
        
