class Solution(object):
    def minRemoveToMakeValid(self, s):
        res = []
        l = 0
        for c in s:
            if c not in '()':
                res.append(c)
                continue
            if c == '(':
                l += 1
                res.append(c)
            else:
                if l > 0:
                    l -= 1
                    res.append(c)
        res = ''.join(res)
        if l:
            res = res[::-1].replace('(', '', l)[::-1]
        return res
            
