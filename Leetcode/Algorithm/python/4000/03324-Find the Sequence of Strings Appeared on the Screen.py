class Solution(object):
    def stringSequence(self, target):
        res = []
        cur = []
        for c in target:
            cur.append('a')
            res.append(''.join(cur))
            while cur[-1] != c:
                cur[-1] = chr(ord(cur[-1]) + 1)
                res.append(''.join(cur))
        return res
