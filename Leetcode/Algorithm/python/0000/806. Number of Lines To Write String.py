class Solution(object):
    def numberOfLines(self, widths, S):
        line = 0
        res = 0
        for c in S:
            u = ord(c) - ord('a')
            line += widths[u]
            if line > 100:
                line = widths[u]
                res += 1
        if line:
            res += 1
        return (res, line)
