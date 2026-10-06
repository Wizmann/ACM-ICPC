class Solution(object):
    def maxDepth(self, s):
        depth = 0
        res = 0
        for c in s:
            if c == '(':
                depth += 1
            elif c == ')':
                depth -= 1
            res = max(res, depth)
        return res
