class Solution(object):
    def makeLargestSpecial(self, S):
        res = []
        u = 0
        pre = 0
        for i, c in enumerate(S):
            if c == '0':
                u -= 1
            else:
                u += 1
                
            if u == 0:
                res.append('1' + self.makeLargestSpecial(S[pre + 1: i]) + '0')
                pre = i + 1
        return ''.join(sorted(res, reverse=True))
