class Solution(object):
    def removeOuterParentheses(self, S):
        st = ""
        deg = 0
        res = ''
        for s in S:
            if s == '(':
                st += s
                deg += 1
            elif s == ')':
                st += s
                deg -= 1
                if deg == 0:
                    res += st[1:-1]
                    st = ''
        return res
            
