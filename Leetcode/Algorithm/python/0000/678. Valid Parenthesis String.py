class Solution(object):
    def checkValidString(self, s):
        l, r = 0, 0
        for c in s:
            if c == '(':
                l += 1
                r += 1
            elif c == ')':
                l -= 1
                r -= 1
                if r < 0:
                    return False
                l = max(l, 0)
            else:
                l = max(l - 1, 0)
                r += 1
        return l == 0
                
