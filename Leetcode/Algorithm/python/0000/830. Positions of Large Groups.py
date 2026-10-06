class Solution(object):
    def largeGroupPositions(self, S):
        n = len(S)
        pre = None
        preIdx = 10 ** 10
        res = []
        for i in xrange(n + 1):
            if i < n and S[i] == pre:
                continue
            else:
                l = i - preIdx
                if l >= 3:
                    res.append([preIdx, i - 1])
                if i < n:
                    preIdx = i
                    pre = S[i]
        return res
